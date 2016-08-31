#include "CPPTextDecorator.h"

CppTextDecorator::CppTextDecorator(void){

    _text_style.emplace("bold", "1");
    _text_style.emplace("faint", "2");
    _text_style.emplace("underlined", "4");
    _text_style.emplace("reverse_color", "7");
    _text_style.emplace("concealed", "8");
    _text_style.emplace("strikethrough", "9");

    _color.emplace("black", "30");
    _color.emplace("red", "31");
    _color.emplace("green", "32");
    _color.emplace("yellow", "33");
    _color.emplace("blue", "34");
    _color.emplace("magenta", "35");
    _color.emplace("cyan", "36");
    _color.emplace("white", "37");

    _bcolor.emplace("black", "40");
    _bcolor.emplace("red", "41");
    _bcolor.emplace("green", "42");
    _bcolor.emplace("yellow", "43");
    _bcolor.emplace("blue", "44");
    _bcolor.emplace("magenta", "45");
    _bcolor.emplace("cyan", "46");
    _bcolor.emplace("white", "47");

    _escape = "\033[";
    _m = "m";
    _end = "\033[0m";
}

std::string CppTextDecorator::BuildStyle(std::vector<std::string> style){

    std::string t;
    for(int i = 0; i < style.size(); i++){
        t += _text_style[style[i]];
        if(i != (style.size() - 1)){
            t += ";";
        }
    }
    return t;
}

std::string CppTextDecorator::MakeColor(std::string text, std::string color){

    std::string t = _escape + _color[color] + _m + text + _end;
    return t;
}

std::string CppTextDecorator::MakeBColor(std::string text, std:: string bcolor){

    std::string t = _escape + _bcolor[bcolor] + _m + text + _end;
    return t;

}

std::string CppTextDecorator::MakeStyle(std::string text, std::vector<std::string> style){

    std::string t = _escape + BuildStyle(style) + _m + text + _end;
    return t;

}

std::string CppTextDecorator::MakeTwoColor(std::string text,
                                        std::string color,
                                        std::string bcolor){

    std::string t = _escape + _color[color] + ";" + _bcolor[bcolor] + _m + text + _end;
    return t;

}


std::string CppTextDecorator::MakeStyleColor(std::string text,
                            std::vector<std::string> style,
                            std::string color){

    std::string t = _escape + BuildStyle(style) + ";" + _color[color] + _m + text + _end;
    return t;
}

std::string CppTextDecorator::MakeStyleBColor(std::string text,
                            std::vector<std::string> style,
                            std::string bcolor){

    std::string t = _escape + BuildStyle(style) + ";" + _bcolor[bcolor] + _m + text + _end;
    return t;
}

std::string CppTextDecorator::MakeFancy(std::string text,
                            std::vector<std::string> style,
                            std::string color, std::string bcolor){

    std::string t = _escape + BuildStyle(style) + ";";
    t+= _color[color] + ";" + _bcolor[bcolor] + _m + text + _end;
    return t;
}

std::string CppTextDecorator::DecorateText(std::string text,
                            std::string color,
                            std::string bcolor,
                            std::vector<std::string> style){

    std::string t;


    if(style.size() > 0 && !(color == "") && !(bcolor == "")){
        t = MakeFancy(text, style, color, bcolor);
    }else if(style.size() > 0 && !(bcolor == "")){
        t = MakeStyleBColor(text, style, bcolor);
    }else if(style.size() > 0 && !(color == "")){
        t = MakeStyleColor(text, style, color);
    }else if(!(color == "") && !(bcolor == "")){
        t = MakeTwoColor(text, color, bcolor);
    }else if(!(color == "")){
        t = MakeColor(text, color);
    }else if(!(bcolor == "")){
        t = MakeBColor(text, bcolor);
    }else if(style.size() > 0){
        t = MakeStyle(text, style);
    }else{
        t = text;
    }
    return t;
}
