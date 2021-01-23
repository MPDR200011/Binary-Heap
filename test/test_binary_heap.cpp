#include "binary_heap.hpp"
#include "catch2/catch.hpp"
#include <iostream>

SCENARIO("binary heap changes size", "[binary_heap]") {
    GIVEN("binary heap has some items") {
        BinaryHeap<int> heap;

        heap.push(4);
        heap.push(2);
        heap.push(10);
        heap.push(-3);
        heap.push(1);

        REQUIRE( heap.size() == 5 );

        WHEN("items are removed") {
            heap.pop();
            THEN("the size changes") {
                REQUIRE( heap.size() == 4 );
            }
        }

        WHEN("items are added") {
            heap.push(6);
            THEN("the size changes") {
                REQUIRE( heap.size() == 6 );
            }
        }
    }
}

SCENARIO("binary heap sorts items", "[binary_heap]") {
    GIVEN("binary heap has some items") {
        BinaryHeap<int> heap;

        heap.push(4);
        heap.push(2);
        heap.push(10);
        heap.push(-3);
        heap.push(1);

        REQUIRE( heap.top() == -3 );
        
        WHEN("new min is added") {
            heap.push(-4);
            THEN("the heaps top changes") {
                REQUIRE( heap.top() == -4 );
            }
        }

        WHEN("non min value is added") {
            heap.push(11);
            THEN("the heaps top doesn't change") {
                REQUIRE( heap.top() == -3 );
            }
        }

        WHEN("value is poped from the heap") {
            heap.pop();
            THEN("the heaps top changes") {
                REQUIRE( heap.top() == 1 );
            }
        }

        WHEN("all values are popped from the heap") {
            std::vector<int> popped;
            while (!heap.empty()) {
                popped.push_back(heap.top());
                heap.pop();
            }
            THEN("they come out in ascending order") {
                REQUIRE( std::is_sorted(std::begin(popped), std::end(popped)) );
            }
        }
    }
}
