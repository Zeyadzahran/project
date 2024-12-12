#include "Playlist.h"
#include <bits\stdc++.h>


Playlist::Playlist(const std::string& name) : name(name) {}

std::string Playlist::getName() const {
    return name;
}

void Playlist::setName(const std::string& name) {
    this->name = name;
}

void Playlist::addShurah(const Shurah& shurah) {
    shurahList.append(shurah);
}

void Playlist::removeShurah( Shurah& shurah) {
    shurahList.remove(shurah);
}
Shurah &Playlist::searchWithName(const std::string &name) {
    for (int i = 0 ; i < shurahList.getSize();i++) {
        if (shurahList.get(i).getName() == name) {
            return shurahList.get(i);
        }
    }
    throw std::invalid_argument("No such shurah");
}


void Playlist::displayContent() const {
    std::cout << '+'<<std::string(32,'-')<< std::endl;
    std::cout << "| Playlist: " << std::setw(20) << std::left << name << "|" << std::endl;
    std::cout << '+'<<std::string(32,'-')<< std::endl;
    for (int i = 0; i < shurahList.getSize(); i++) {
        const Shurah& shurah = shurahList.get(i);
        std::cout << shurah ;
    }

}


const Shurah &Playlist::getShurah(int index) const {
    return shurahList.get(index);
}

int Playlist::getShurahCount() const {
    return shurahList.getSize();
}
bool Playlist::operator==(const Playlist &other) const {
    return getName() == other.getName();

}



