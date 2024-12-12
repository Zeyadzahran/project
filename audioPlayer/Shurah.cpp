//
// Created by zeyad on 03/12/2024.
//
#include "Shurah.h"
#include <bits\stdc++.h>
using namespace std;

Shurah::Shurah(const std::string& name, const std::string& path, const std::string& type)
    : name(name), path(path), type(type) {}

std::string Shurah::getName() const {
    return name;
}

void Shurah::setName(const std::string& name) {
    this->name = name;
}

std::string Shurah::getPath() const {
    return path;
}

void Shurah::setPath(const std::string& path) {
    this->path = path;
}

std::string Shurah::getType() const {
    return type;
}

void Shurah::setType(const std::string& type) {
    this->type = type;
}

ostream& operator<<(std::ostream& os, const Shurah& shurah) {
    const int col1Width = 20;
    const int col2Width = 25;
    const int col3Width = 15;
    os << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << string(col3Width, '-') << "+" << endl;
    os << "|" << setw(col1Width) << left << "Surah Name"
       << "|" << setw(col2Width) << left << "Path"
       << "|" << setw(col3Width) << left << "Type"
       << "|" << endl;
    os << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << string(col3Width, '-') << "+" << endl;
    os << "|" << setw(col1Width) << left << shurah.getName()
       << "|" << setw(col2Width) << left << shurah.getPath()
       << "|" << setw(col3Width) << left << shurah.getType()
       << "|" << endl;
    os << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << string(col3Width, '-') << "+" << endl;
    return os;
}
bool Shurah::operator==(const Shurah& other) const {
    return name == other.name && path == other.path && type == other.type;
}
