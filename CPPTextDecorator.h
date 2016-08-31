#ifndef CPPTEXTDECORATOR
#define CPPTEXTDECORATOR

#include <unordered_map>
#include <string>
#include <vector>

class CppTextDecorator{

    private:
        std::unordered_map<std::string, std::string> _text_style;
        std::unordered_map<std::string, std::string> _color;
        std::unordered_map<std::string, std::string> _bcolor;
        std::string _escape;
        std::string _m;
        std::string _end;
        std::string BuildStyle(std::vector<std::string>);
        std::string MakeColor(std::string text, std::string color);
        std::string MakeBColor(std::string text, std::string bcolor);
        std::string MakeStyle(std::string text, std::vector<std::string> style);
        std::string MakeTwoColor(std::string text, std::string color, std::string bcolor);
        std::string MakeStyleColor(std::string text, std::vector<std::string> style, std::string color);
        std::string MakeStyleBColor(std::string text, std::vector<std::string> style,
                                    std::string bcolor);
        std::string MakeFancy(std::string text, std::vector<std::string> style,
                            std::string color, std::string bcolor);

    public:
        CppTextDecorator(void);
        std::string DecorateText(std::string text,
                            std::string color="",
                            std::string bcolor="",
                            std::vector<std::string> style = {});
};

#endif
