#include <iostream>

using namespace std;

int main(){

    cout << "Hello, welcome to Javi's Carpet Cleaning Service" << endl;
    cout << "\nHow many small rooms would you like cleaned? ";
    int small_rooms;
    cin >> small_rooms;
    cout << "How many large rooms would you like cleaned? ";
    int large_rooms;
    cin >> large_rooms;
    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    
    const double price_small_room {25.0};
    const double price_large_room {35.0};
    const double tax_rate {0.06};
    const int expiry_time {30}; //days

    cout << "Price per small room: €" << price_small_room << endl;
    cout << "Price per large room: €" << price_large_room << endl;
    
    cout << "Cost: €" << price_small_room * small_rooms + price_large_room * large_rooms << endl;
    cout << "Tax: €" << 0.06 * (price_small_room * small_rooms + price_large_room * large_rooms) << endl;
    cout << "==========================================" << endl;
    cout << "Total estimate: €" << (price_small_room * small_rooms + price_large_room * large_rooms) + \
                                    (0.06 * (price_small_room * small_rooms + price_large_room * large_rooms)) << endl;

    cout << "This estimate is valid for " << expiry_time << " days" << endl;

    return 0;
}