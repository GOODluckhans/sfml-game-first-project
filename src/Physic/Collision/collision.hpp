#pragma once
#include "../../../MainLibraries/main.hpp"

class Collision {
private:
public:
	Collision() {}
	template<typename T>
	static sf::FloatRect getBounds(const T& obj) {
		if constexpr (requires { obj.getGlobalBounds(); }) {
			return obj.getGlobalBounds();
		}
		else if constexpr (requires { obj.rect; }) {
			return obj.rect;
		}
		else if constexpr (std::is_same_v<T, sf::FloatRect>) {
			return obj;
		}
		else {
			static_assert(sizeof(T) == 0,
				"Type does not provide getGlobalBounds(), rect, or is not sf::FloatRect");
		}
	}

	template<typename A, typename B>
	static bool isColliding(const A& a, const B& b) {
		sf::FloatRect aBound = getBounds(a);
		sf::FloatRect bBound = getBounds(b);

		return aBound.findIntersection(bBound).has_value();
	}

	template<typename item1 , typename item2>
	void ifColliding(item1& obj1, item2& obj2, bool isSolid) {
		if (isSolid) {
			sf::FloatRect objBounds;
			sf::FloatRect objBounds2; // Only declare once

			if constexpr (requires { obj2.getGlobalBounds(); }) {
				objBounds2 = obj2.getGlobalBounds();

			}
			else if constexpr (requires { obj2.rect; }) {
				objBounds2 = obj2.rect;

			}
			else if constexpr (std::is_same_v<item2, sf::FloatRect>) {
				objBounds2 = obj2;
			}
			else {
				static_assert(false, "obj2 type does not have getGlobalBounds() or rect member.");
			}

			if constexpr (requires { obj1.getGlobalBounds(); }) {
				objBounds = obj1.getGlobalBounds();

			}
			else if constexpr (requires { obj1.rect; }) {
				objBounds = obj1.rect;

			}
			else if constexpr (std::is_same_v<item1, sf::FloatRect>) {
				objBounds = obj1;
			}
			else {
				static_assert(false, "obj1 type does not have getGlobalBounds() or rect member.");
			}

			float overlapLeft = (objBounds.position.x + objBounds.size.x) - objBounds.position.x;
			float overlapRight = (objBounds2.position.x + objBounds2.size.x) - objBounds.position.x;
			float overlapTop = (objBounds.position.y + objBounds.size.y) - objBounds2.position.y;
			float overlapBottom = (objBounds2.position.y + objBounds2.size.y) - objBounds.position.y;

			// Find smallest overlap
			float minX = std::min(overlapLeft, overlapRight);
			float minY = std::min(overlapTop, overlapBottom);

			if (minX < minY) {
				// Resolve X only

				if (overlapLeft < overlapRight)
					obj1.setPosition({ objBounds2.position.x - objBounds.size.x, objBounds.position.y });
				else
					obj1.setPosition({ objBounds2.position.x + objBounds2.size.x, objBounds.position.y });

			}
			else {
				// Resolve Y only
					if (overlapTop < overlapBottom)
						obj1.setPosition({ objBounds.position.x, objBounds2.position.y - objBounds.size.y });
					else
						obj1.setPosition({ objBounds.position.x, objBounds2.position.y + objBounds2.size.y });
				}

		}

		//no solid

	}
	template<typename OBJ1>
	void inverseCollision(OBJ1& obj1,const sf::FloatRect& objBounds, const sf::FloatRect& objBounds2) {
		float overlapLeft = (objBounds.position.x + objBounds.size.x) - objBounds.position.x;
		float overlapRight = (objBounds2.position.x + objBounds2.size.x) - objBounds.position.x;
		float overlapTop = (objBounds.position.y + objBounds.size.y) - objBounds2.position.y;
		float overlapBottom = (objBounds2.position.y + objBounds2.size.y) - objBounds.position.y;

		// Find smallest overlap
		float minX = std::min(overlapLeft, overlapRight);
		float minY = std::min(overlapTop, overlapBottom);

		if (minX < minY) {
			// Resolve X only

			if (overlapLeft < overlapRight)
				obj1.setPosition({ objBounds2.position.x + objBounds.size.x, objBounds.position.y });
			else
				obj1.setPosition({ (objBounds2.position.x + objBounds2.size.x) - (objBounds.size.x + 10.f), objBounds.position.y });

		}
		else {
			// Resolve Y only
			if (overlapTop < overlapBottom)
				obj1.setPosition({ objBounds.position.x, objBounds2.position.y + objBounds.size.y });
			else
				obj1.setPosition({ objBounds.position.x, (objBounds2.position.y + objBounds2.size.y) - (objBounds.size.y + 10.f) });
		}
	}


};