#include "MediaPlayer.h"
#include <windows.h>
#include <bits\stdc++.h>
#include<conio.h>
using namespace std;
void MediaPlayer::addPlaylist(const std::string& name) {
    Playlist playlist(name);
    playlists.append(playlist);
}
void MediaPlayer::addShurahToPlaylist(const std::string& playlistName, const Shurah& shurah) {
    for (int i = 0; i < playlists.getSize(); i++) {
        if (playlists.get(i).getName() == playlistName) {
            playlists.get(i).addShurah(shurah);
            return;
        }
    }
    std::cout << "Playlist not found!\n";
}


void MediaPlayer::removePlaylist(const std::string &name) {

    for (int i = 0; i < playlists.getSize(); i++) {
        Playlist& currentPlaylist = playlists.get(i);
        if (currentPlaylist.getName() == name) {
            playlists.remove(currentPlaylist);
            std::cout << "Playlist " << name << " removed successfully." << std::endl;
            return;;
        }
    }
    throw std::runtime_error("Playlist with name " + name + " not found.");
}

Playlist& MediaPlayer::SearchWithPlaylistName(const std::string &name) const {
    for (int i = 0; i < playlists.getSize(); i++) {
        Playlist& currentPlaylist = playlists.get(i);
        if(currentPlaylist.getName() == name) {
            return currentPlaylist;
        }
    }
    throw std::runtime_error("Playlist with name '" + name + "' not found.");
}
Shurah &MediaPlayer::searchAboutSurah(const std::string& playlistName ,const std::string &surhahName) const {
    Playlist& curPlaylist = SearchWithPlaylistName(playlistName);
    return  curPlaylist.searchWithName(surhahName);
}

void MediaPlayer::displayAllPlaylists() const {

    const int col1Width = 15;
    const int col2Width = 20;

    // Print top border
    cout << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << endl;

    cout << "|" << setw(col1Width) << left << "Playlist Name"
         << "|" << setw(col2Width) << left << "Number of Surahs"
         << "|" << endl;

    cout << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << endl;

    for (int i = 0; i < playlists.getSize(); i++) {
        const Playlist& playlist = playlists.get(i);
        cout << "|" << setw(col1Width) << left << playlist.getName()
             << "|" << setw(col2Width) << left << playlist.getShurahCount()
             << "|" << endl;
    }


    cout << "+" << string(col1Width, '-') << "+" << string(col2Width, '-') << "+" << endl;
}

void MediaPlayer::displayPlaylistsContent() const {

    for (int i = 0; i < playlists.getSize(); i++) {
        const Playlist& playlist = playlists.get(i);
        playlist.displayContent();
        cout<<endl;
    }

}

void MediaPlayer::displaySpecificPlaylist(int& index) const {
   Playlist&  playlist=  playlists.get(index);
   playlist.displayContent();
}
void MediaPlayer::displaySpecficSurah(const std::string& playlistName,const std::string &surhahName) const {
    Shurah &surah = searchAboutSurah(playlistName,surhahName);
    std::cout<<surah;
      std::cout << std::endl;

}
// void MediaPlayer::playSurahFromPlaylist(const std::string& playlistName) {
//     Playlist& playlist = SearchWithPlaylistName(playlistName);
//     int totalShurah = playlist.getShurahCount();
//     if (totalShurah == 0) {
//         std::cout << "No Shurah in the playlist to play.\n";
//         return;
//     }
//     int currentIndex = 0;
//
//
//     while (true) {
//         Shurah& currentShurah = playlist.getShurah(currentIndex);
//
//
//             std::cout << "Now playing: " << currentShurah.getName() << "\n";
//             PlaySound(currentShurah.getPath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
//
//         std::cout << "Use arrows to navigate, 'q' to quit.\n";
//
//         char key = getch();
//         if (key == 'q' || key == 'Q') {
//             PlaySound(NULL, 0, 0); // Stop playback
//             std::cout << "Exiting playback.\n";
//             break;
//         }
//         switch (key) {
//             case 72: // Up arrow
//                     std::cout << "Resuming playback.\n";
//                     PlaySound(NULL, 0, 0); // Pause playback
//                 break;
//             case 75: // Left arrow
//                 PlaySound(NULL, 0, 0); // Stop playback
//                 currentIndex = (currentIndex - 1 + totalShurah) % totalShurah;
//                 break;
//             case 77: // Right arrow
//                 PlaySound(NULL, 0, 0); // Stop playback
//                 currentIndex = (currentIndex + 1) % totalShurah;
//
//                 break;
//             case 80: // Down arrow
//                 std::cout << "Pausing playback.\n";
//                  PlaySound(NULL, 0, 0); // Pause playback
//                 break;
//             default:
//                 std::cout << "Invalid input.\n";
//         }
//     }
// }


void MediaPlayer::playSurahFromPlaylist(const std::string& playlistName) {
    try {
        Playlist& playlist = SearchWithPlaylistName(playlistName);
        if (playlist.getShurahCount() == 0) {
            std::cout << "No Surah found in this playlist.\n";
            return;
        }

        int currentIndex = 0;
        int surahCount = playlist.getShurahCount();

        while (true) {
            const Shurah& shurah = playlist.getShurah(currentIndex);
            std::string command = "open " + shurah.getPath() + " type mpegvideo alias audio";
            mciSendString(command.c_str(), nullptr, 0, nullptr);
            mciSendString("play audio", nullptr, 0, nullptr);

            std::cout << "Now playing: " << shurah.getName() << "\n";
            std::cout << "Press 'q' to stop playback and return to the menu.\n";

            char key;
            while (true) {
                key = _getch();
                if (key == 'q') {
                    mciSendString("stop audio", nullptr, 0, nullptr);
                    mciSendString("close audio", nullptr, 0, nullptr);
                    std::cout << "Stopped playback.\n";
                    return;
                } else if (key == 80) { // Down arrow

                    mciSendString("pause audio", nullptr, 0, nullptr);
                    std::cout << "Playback paused.\n";

                } else if (key == 72) { // Up arrow

                    mciSendString("resume audio", nullptr, 0, nullptr);
                    std::cout << "Playback resumed.\n";

                } else if (key == 75) { // Left arrow

                    mciSendString("stop audio", nullptr, 0, nullptr);
                    mciSendString("close audio", nullptr, 0, nullptr);
                    currentIndex = (currentIndex - 1 + surahCount) % surahCount; // Go to previous Surah
                    break;

                } else if (key == 77) { // Right arrow
                    mciSendString("stop audio", nullptr, 0, nullptr);
                    mciSendString("close audio", nullptr, 0, nullptr);
                    currentIndex = (currentIndex + 1) % surahCount; // Go to next Surah
                    break;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
void MediaPlayer::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::ios_base::failure("Failed to open the file for writing.");
    }

    for (int i = 0; i < playlists.getSize(); i++) {
        const Playlist& playlist = playlists.get(i);


        outFile << "+" << std::string(32, '-') << "\n";
        outFile << "| Playlist: " << std::setw(20) << std::left << playlist.getName() << "|\n";
        outFile << "+" << std::string(32, '-') << "\n";


        for (int j = 0; j < playlist.getShurahCount(); j++) {
            outFile << playlist.getShurah(j);
        }

        outFile << "\n";
    }

    outFile.close();
}
void MediaPlayer::loadFromFile(const std::string& filename) {

}


void MediaPlayer::cleaAllPlaylists() {
    playlists.clear();
}



