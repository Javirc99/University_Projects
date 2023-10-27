// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    // This function should display the current playlist
    // and then the current song playing.

    std::cout << std::endl;

    for (auto &item : playlist)
    {
        std::cout << item << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Current song: " << std::endl;
    std::cout << current_song << std::endl
              << std::endl;
}

int main()
{

    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();

    char selection;

    do
    {
        display_menu();
        std::cin >> selection;
        switch (toupper(selection))
        {
        case 'L':
            display_playlist(playlist, *current_song);
            break;

        case 'F':
            current_song = playlist.begin();
            display_playlist(playlist, *current_song);
            break;

        case 'N':
            *current_song++;
            if (current_song == playlist.end())
            {
                std::cout << "No more songs in the playlists, playing the first song instead" << std::endl;
                current_song = playlist.begin();
            }
            display_playlist(playlist, *current_song);
            break;

        case 'P':
            if (current_song == playlist.begin())
            {
                std::cout << "Reached beginning of the playlist, use 'Next' option to move next" << std::endl;
            }
            else
            {
                *current_song--;
            }
            display_playlist(playlist, *current_song);
            break;

        case 'A':
        {
            // Clearing input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string new_name;
            std::string new_artist;
            int new_rating{};

            std::cout << "Enter the new song's name: ";
            getline(std::cin, new_name);
            std::cout << "Enter the new song's artist name: ";
            getline(std::cin, new_artist);
            std::cout << "Enter the new song's rating: ";
            std::cin >> new_rating;

            Song new_song{new_name, new_artist, new_rating};

            playlist.insert(current_song, new_song);
            *current_song--; // Move to the new song added before the current one and play it;
            display_playlist(playlist, *current_song);
            break;
        }

        default:
            break;
        }

    } while (toupper(selection) != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}