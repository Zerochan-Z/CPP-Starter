#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Movie {
    std::string Title;
    double rating;
    int year;
};

int main() {
    std::vector <Movie> List;

    List.push_back({"The Matrix", 8.7, 1999});
    List.push_back({"Inception", 8.8, 2010});
    List.push_back({"The Godfather", 9.2, 1972});
    List.push_back({"Interstellar", 8.6, 2014});
    List.push_back({"Pulp Fiction", 8.9, 1994});


    for (int i = 0;i < List.size(); i++) {
        std::cout << List[i].Title << " - " <<
                     List[i].rating << " (" << 
                     List[i].year << ") \n";
    }

    std::cout << "After sorted (Rating): " << std::endl;
    std::sort(List.begin(), List.end(), [](const Movie &a, const Movie &b){
        return a.rating > b.rating;
    });

    for (int i = 0;i < List.size(); i++) {
        std::cout << List[i].Title << " - " <<
                     List[i].rating << " (" << 
                     List[i].year << ") \n";
    }
    
    return 0;
}