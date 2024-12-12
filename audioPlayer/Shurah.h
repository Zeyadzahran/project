//
// Created by zeyad on 03/12/2024.
//

#ifndef SHURAH_H
#define SHURAH_H

#include <string>

class Shurah {
private:
    std::string name;
    std::string path;
    std::string type;

public:
    Shurah(const std::string& name = "", const std::string& path = "", const std::string& type = "");

    std::string getName() const;
    void setName(const std::string& name);

    std::string getPath() const;
    void setPath(const std::string& path);

    std::string getType() const;
    void setType(const std::string& type);
    friend std::ostream& operator<<(std::ostream& os, const Shurah& shurah);
    bool operator==(const Shurah& other) const;
};

#endif
