#include <iostream>
#include <array>

template <typename T, size_t N>
class Array
{
private:
    T my_data[N];
    int size = 0;

public:
    constexpr int Capacity() const noexcept { return N; }

    T &operator[](int index)
    {
        size++;
        return my_data[index];
    }

    T at(int index)
    {
        return my_data[index];
    }

    constexpr bool Empty() const noexcept
    {
        if (N == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Fill(T value)
    {

        for (int i = 0; i < N; i++)
        {
            my_data[i] = value;
            size++;
        }
    }

    int Size()
    {
        return size;
    }
};

int main()
{
    Array<int, 5> data;
    data[0] = 4;
    data[1] = 10;
    Array<int, 0> data2;

    std::cout << data.Size() << std::endl;

    int size = data.Size();

    for (int i = 0; i < size; i++)
    {
        std::cout << data.at(i) << " ";
    }

    std::cout << std::endl;

    std::cout << data.Size() << std::endl;

    std::cout << data.Capacity() << std::endl;

    std::cout << data.at(1) << std::endl;

    std::cout << data.Size() << std::endl;

    return 0;
}