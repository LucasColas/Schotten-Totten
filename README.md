# Schotten-Totten

Schotten Totten implemented in C++.
This game is implemented in french.

## How to install it
```bash
git clone git@github.com:LucasColas/Schotten-Totten.git
```

Run : 
```
main.cpp
```
In CMakeLists.txt you might need to change this line :
```
set(CMAKE_PREFIX_PATH "C://Qt//6.5.0//mingw_64//lib//cmake")
```
You have two options : 
* only change the path with your path to find cmake of Qt
* delete this line and write ```find_package(Qt6 COMPONENTS Widgets REQUIRED)```

You can play Schotten Totten in Console or with Qt.
## Console
Just run 
```
main.cpp
```

## Qt 

Change the code of the main function with this code : 

```cpp
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    VueMenu vueMenu;
    vueMenu.show();

    return app.exec();

}
```


