#include "2022/tasks.h"
#include <set>

void day1(std::string &filename)
{
    // file must exist
    ASSERT(std::filesystem::exists(filename), "Given file does not exist: " << filename);

    // read input, process by each line
    std::ifstream instream;
    instream.open(filename);

    auto capacitySet = std::set<int, std::greater<int>>{}; // slow

    if (!instream)
    {
        ASSERT(false, "Cannot read file: " << filename);
    }
    int rolling = 0;
    int tmp = 0;
    while (!instream.eof())
    {
        if (instream.peek() == '\n')
        {
            capacitySet.insert(rolling);
            rolling = 0;
            instream.get(); // to move the processor forward
            continue;
        }
        instream >> tmp;
        instream.get(); // to move the processor forward
        rolling += tmp;
    }
    instream.close();

    int sum = 0;
    int i = 0;
    for (auto itr = capacitySet.begin(); itr != capacitySet.end() && i < 3; itr++)
    {
        sum += *itr;
        i++;
    }

    std::cout << "Higest capacity elf: " << *(capacitySet.begin()) << std::endl;
    std::cout << "Top 3 sum: " << sum << std::endl;
}