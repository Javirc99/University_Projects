#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main() {
    Tours tours
    {
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janeiro", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
                },
            },
            {
                "Argentina", {
                    { "Buenos Aires", 3010000, 723.77 }
                },
            },
        }
    };

    // Set column widths
    int countryWidth = 15;
    int cityWidth = 20;
    int populationWidth = 20;
    int priceWidth = 10;

    // Display the table header
    std::cout << std::left << std::setw(countryWidth) << "Country"
              << std::setw(cityWidth) << "City"
              << std::setw(populationWidth) << "Population"
              << std::setw(priceWidth) << "Price" << std::endl;
    std::string separator(65, '-');
    std::cout << separator << std::endl;

    // Display the table content
    for (const auto& country : tours.countries) {

        
        for (const auto& city : country.cities) {
            std::cout << std::left << std::setw(countryWidth) << country.name
                      << std::setw(cityWidth) << city.name
                      << std::setw(populationWidth) << city.population
                      << std::fixed << std::setprecision(2) << std::setw(priceWidth) << city.cost
                      << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}
