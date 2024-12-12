#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Shurah.h"
#include "DoublyLinkedList.h"
#include <string>
#include <windows.h>

class Playlist {
private:
    std::string name;
    DoublyLinkedList<Shurah> shurahList;

public:
    Playlist(const std::string& name = "");

    std::string getName() const;
    void setName(const std::string& name);

    void addShurah(const Shurah& shurah);
    void removeShurah( Shurah& shurah);
    void displayContent() const;
    const Shurah& getShurah(int index) const;
    int getShurahCount() const;
    Shurah &searchWithName(const std::string& name);
    bool operator==(const Playlist& other) const;
};

#endif
