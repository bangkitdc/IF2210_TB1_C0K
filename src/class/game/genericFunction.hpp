#include <iostream>
#include <vector>
#include <deque>
#include "../inventoryHolder/Player.hpp"
#include "../inventoryHolder/deckCard.hpp"

template <typename Container>
typename Container::value_type getMaxValue(const Container &container)
{
    typename Container::value_type max_val = container.front();
    for (const auto &val : container)
    {
        if (val > max_val)
        {
            max_val = val;
        }
    }
    return max_val;
}