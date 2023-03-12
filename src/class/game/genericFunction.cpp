template <typename Container>
typename Container::value_type getMaxValue(const Container& container)
{
    typename Container::value_type max_val = container.front();
    for(const auto& val : container)
    {
        if(val.getValueGeneric() > max_val.getValueGeneric())
        {
            max_val = val;
        }
    }
    return max_val;
}
