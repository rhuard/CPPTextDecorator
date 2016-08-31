# CPPTextDecorator (ideal-giggle)

C++ Text Decorator: this is a port to C++ of my PYTextDecorator.
 Uses the ANSI escape characters to allow python code to print different
 styles and colors to the console screen.

## usage:
```c++
#include <iostream>
#include<string>
#include<vector>
#include "CPPTextDecorator.h"

int main(){

    std::string text = "Hello World";
    CppTextDecorator td = CppTextDecorator();

    std::vector<std::string> style = std::vector<std::string>();

    style.push_back("bold");
    style.push_back("underlined");
    
    std::string new_text = td.DecorateText(text, "green","red", style);

    std::cout << new_text << std::endl;

    return 0;
}

```

if you would like only the color you can do
```c++
std::string new_text = td.DecorateText(text, "green");
```

likewise if you want only the text color and background color you can do
```c++
std::string new_text = td.DecorateText(text, "green", "red");
```

However, if you want only the background color, the color must be an empty string
```c++
std::string new_text = td.DecorateText(text, "", "red");
```

similarly, for just style changes:
```c++
    std::vector<std::string> style = std::vector<std::string>();

    style.push_back("bold");
    style.push_back("underlined");
    
    std::string new_text = td.DecorateText(text, "","", style);
```

The style parameter must be passed in as a vector, even if there is only one item.

## Options
colors (both background and foreground) supported:
* black
* red
* green
* yellow
* blue
* magenta
* cyan
* white

Styles supported:
* bold
* faint
* underline
* reverse_color
* concealed
* strikethrough
