#include <iostream>
#include<windows.h>
#include "MediaPlayer.h"
#include "Playlist.h"
#include "Shurah.h"
using namespace std;
void startmenu();
# pragma comment(lib,"winmm.lib")
int main() {
    int choice;
    MediaPlayer player;
    while (true) {
        startmenu();
        cout<<"Enter ur choice : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string playlistname;
                cout << "Enter playlist name: ";
                cin >> playlistname;
                player.addPlaylist(playlistname);
                break;
            }
            case 2: {
                player.displayAllPlaylists();
                cout << "Enter playlist name: ";
                string playlistname;
                cin >> playlistname;
                cout<<"surah name : ";
                string surahname;
                cin >> surahname;
                cout<<"Enter surah type :";
                string type;
                cin >> type;
                cout<<"surah path : ";
                string path;
                cin >> path;
                Shurah shurah(surahname,path,type);
                player.addShurahToPlaylist(playlistname,shurah);
                   /* while (true) {
                        cout<<"Add anthor surah to playlist ?( y / n ) ";
                        char coice;
                        cin>>coice;
                        if (choice == 'y' or choice == 'Y') {
                            cout<<"surah name : ";
                          //  string surahname;
                            cin >> surahname;
                            cout<<"Enter surah type :";
                          //  string type;
                            cin >> type;
                            cout<<"surah path : ";
                            //string path;
                            cin >> path;
                            Shurah s(surahname , path, type);
                            player.addShurahToPlaylist(playlistname,s);
                        }
                        else {
                            break ;
                        }
                    }*/
                break;
            }
            case 3: {
                player.displayAllPlaylists();
                cout<<"Enter Playlist Name : ";
                 string playlistname;
                cin >> playlistname;
                Playlist &cur = player.SearchWithPlaylistName(playlistname);
                cur.displayContent();
                cout<<"Enter surah name : ";
                string surahname;
                cin >> surahname;
                Shurah& shurah = cur.searchWithName(surahname);
                cur.removeShurah(shurah);
                break;
            }
            case 4: {
                player.displayAllPlaylists();
                break;
            }
            case 5: {
                player.displayPlaylistsContent();
                break;
            }
            case 6: {
                player.displayAllPlaylists();
                cout<<"Enter PLayist Name : ";
                string name;
                cin>>name;
                cout<<"Enter Surah Name : ";
                string surahname;
                cin>>surahname;
                player.displaySpecficSurah(name,surahname);
                break;
            }
            case 7 : {
                player.displayAllPlaylists();
                std::cout << "Enter Playlist Name to play: ";
                std::string playlistName;
                std::cin >> playlistName;
                player.playSurahFromPlaylist(playlistName);
                break;

            }
            case 8: {
                cout << "Enter filename to save playlists: ";
                string filename;
                cin >> filename;
                    player.saveToFile(filename);
                    cout << "Playlists saved successfully.\n";
                break;
            }
            case 9: {
                cout << "Enter filename to load playlists: ";
                string filename;
                cin >> filename;
                    player.loadFromFile(filename);
                    cout << "Playlists loaded successfully.\n";

                break;
            }
            case 10: {
                player.displayAllPlaylists();
                cout<<"Enter Playlist Name to be Deleted : ";
                string name;
                cin>>name;
                player.removePlaylist(name);
            }
            case 11: {
                player.cleaAllPlaylists();
                break;
            }
            default:
                cout<<"Invalied Input\n";
            break;

        }

    }



    return 0;
}
void startmenu() {
    cout<<"1 - Add new playlist\n"<<
        "2 - Add Surah to an existing playlist\n"<<
            "3 - Remove Shurah from an existing playlist\n"<<
                    "4 - Display all current playlists\n"<<
                        "5 - Display all audio  in playlists\n"<<
                            "6 - Display Shurah in a specific playlist\n"<<
                                "7 - Play Shurah from a specific playlist\n"<<
                                    "Use left arrow (<-) to play the previous Shurah\n"<<
                                       "Use right arrow (->) to play the next Shurah\n"<<
                                           "Use up arrow (^) to pause the current Shurah\n"<<
                                               "Use down arrow (v) to resume the current Shurah\n"<<
                                                   "Press q to exit the current playlist and return to the menu\n"<<
                                                       "8 - Save an existing playlist to a file\n"<<
                                                           "9 - Load an existing playlist from a file\n"<<
                                                               "10 - Remove an existing playlist\n"<<
                                                                   "11 - Exit\n";
}