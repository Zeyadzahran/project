#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "Playlist.h"

#include <string>

class MediaPlayer {
private:
    DoublyLinkedList<Playlist> playlists;


public:

    void addPlaylist(const std::string& name);
    void removePlaylist(const std::string& name);
    void displayAllPlaylists() const;
    void displayPlaylistsContent() const;
    void displaySpecificPlaylist(int& index) const;
    Playlist& SearchWithPlaylistName(const std::string &name) const;
    void addShurahToPlaylist(const std::string& playlistName, const Shurah& shurah);
    Shurah& searchAboutSurah(const std::string& playlistName ,const std::string &surhahName) const;
    void displaySpecficSurah(const std::string& playlistName,const std::string &surhahName) const;
    void playSurahFromPlaylist(const std::string& playlistName);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void cleaAllPlaylists();


};

#endif
