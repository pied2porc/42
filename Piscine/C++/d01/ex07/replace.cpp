#include <string>
#include <fstream>
#include <iostream>

std::string get_output_filename(std::string ifname)
{
    size_t pos{ ifname.find_last_of('.') };
    return pos == std::string::npos ?
        ifname + ".replace" :
        ifname.replace(pos, ifname.size() - pos, ".replace");
}

void ft_replace(std::string& input, const std::string& s1,
    const std::string& s2)
{
    size_t pos{ 0 };
    while ((pos = input.find(s1, pos)) != std::string::npos) {
        input.replace(pos, s1.size(), s2);
        pos += s2.size();
    }
}

int main(int ac, char* av[])
{
    if (ac != 4) {
        std::cout << "Usage: replace <filename> s1 s2\n"
            << "s1: string to replace.\n"
            << "s2: replacement string.\n";
        return EXIT_FAILURE;
    }
    std::ifstream ifs{ av[1] };
    if (!ifs) {
        std::cout << "Failed to open " << av[1] << "\n";
        return EXIT_FAILURE;
    }
    std::string ofname{ get_output_filename(av[1]) };
    std::ofstream ofs{ ofname };
    if (!ofs) {
        std::cout << "Failed to open " << ofname << "\n";
        return EXIT_FAILURE;
    }
    while (ifs) {
        std::string input;
        std::getline(ifs, input);
        ft_replace(input, av[2], av[3]);
        ofs << input;
        if (ifs.peek() != EOF) ofs << "\n";
    }
    return EXIT_SUCCESS;
}