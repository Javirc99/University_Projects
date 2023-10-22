// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>

using namespace std;

int answer_checker(std::string model, std::string answer){

    int n_of_correct{0};

    for(int i = 0; i < model.length(); i++){
        if(answer[i] == model[i]){
            n_of_correct++;
        }
    }
    return n_of_correct;
}

int main() {
    
    std::ifstream file;
    file.open("responses.txt");
    std::string model_answer;

    

    std::string student_name, student_answer;

    int number_of_students{0};
    double average_score{0.0};


    if(file){
        cout << "file opened properly" << endl;

        file >> model_answer;
        int max_score = model_answer.length();

        while(!file.eof()){
            file >> student_name;
            file >> student_answer;
            int score = answer_checker(model_answer, student_answer);
            cout << "Student: " << student_name << " ; Score: " << score << "/" << max_score << endl;
            number_of_students++;
            average_score += score;
        }

        average_score /= static_cast<double>(number_of_students);

        cout << "--------------------------";
        cout << endl << "Average score: " << average_score << endl;


    }else{
        cout << "Error opening the file" << endl;
    }
    

    
    return 0;
}

