#include "pch.h"
#include "CppUnitTest.h"
#include <unordered_set>
#include "../Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointTest {
	TEST_CLASS(UnitTest1) {
public:

	TEST_METHOD(TestSetFunction) {
		auto* set = new std::unordered_set<Point*>();
		auto* point1 = new Point(1, 1);
		auto* point2 = new Point(1, 1);

		set->insert(point1);
		set->insert(point2);

		Assert::AreEqual(1, (int) set->size());
	}
	};
}
