#include <algorithm> // Add this header for std::all_of
#include "exam.hpp"

// ==> Store data of exam in a file
void exam::store_data()
{
    std::ofstream file;

    file.open(".system/exam_token/current_token.txt");
    file << get_start_time() << std::endl;
    file << get_end_time() << std::endl;
    file << get_exam_number() << std::endl;
    file << student << std::endl;
    file << get_lvl() << std::endl;
    file << current_ex->get_assignement() << std::endl;
    file << current_ex->get_name() << std::endl;
    file << level_max << std::endl;
    file << current_ex->time_bef_grade << std::endl;
    file << level_per_ex << std::endl;
    file << level_per_ex_save << std::endl;
    file << using_cheatcode << std::endl;

    file.close();
}

// ==> restore an old version of exam
void exam::restore_data(void)
{
    std::ifstream file;
    exam backup;
    std::string name;
    std::string assign;
    std::string time_bef_grade;
    time_t t;
    file.open(".system/exam_token/current_token.txt", std::ios::in);
    if (file.is_open())
    {
        file >> backup.start_time;
        file >> backup.end_time;
        file >> backup.exam_number;
        file >> backup.student;
        file >> backup.level;
        file >> assign;
        file >> name;
        file >> backup.level_max;
        file >> time_bef_grade;
        file >> backup.level_per_ex;
        file >> backup.level_per_ex_save;
        file >> backup.using_cheatcode;

        // Debugging: Print the values read from the file
        std::cout << "Debug: assign = '" << assign << "', time_bef_grade = '" << time_bef_grade << "'" << std::endl;

        // Validate that 'assign' and 'time_bef_grade' are not empty
        if (assign.empty() || time_bef_grade.empty())
        {
            std::cerr << "Error: Missing data in file. Empty value encountered." << std::endl;
            file.close();
            return;
        }

        // Validate that 'assign' and 'time_bef_grade' are integers
        if (!std::all_of(assign.begin(), assign.end(), ::isdigit) || 
            !std::all_of(time_bef_grade.begin(), time_bef_grade.end(), ::isdigit))
        {
            std::cerr << "Error: Invalid data in file. Non-numeric value encountered." << std::endl;
            file.close();
            return;
        }

        try
        {
            int assign_int = std::stoi(assign);
            int time_bef_grade_int = std::stoi(time_bef_grade);

            // Safely allocate memory for the exercise
            try
            {
                backup.current_ex = new exercise(backup.get_lvl(), name, assign_int, time_bef_grade_int);
            }
            catch (const std::bad_alloc &e)
            {
                std::cerr << "Error: Memory allocation failed while creating exercise." << std::endl;
                file.close();
                return;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid data in file. Could not convert to integer." << std::endl;
            file.close();
            return;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: Integer value out of range in file." << std::endl;
            file.close();
            return;
        }

        backup.backup = 1;
        file.close();
    }
    else
    {
        std::cerr << "Error: Can't open backup file." << std::endl;
    }

    file.close();

    if (backup.end_time > time(0))
    {
        system("clear");
        std::cout << std::endl
                  << RED << BOLD << "       !!" << BOLD << WHITE << " BACKUP " << RED << BOLD << "!!" << std::endl
                  << std::endl;
        if (backup.student)
            std::cout << WHITE << BOLD << "        EXAMRANK " << LIME << "0" << backup.exam_number << WHITE << std::endl;
        else
            std::cout << WHITE << BOLD << "        EXAMWEEK " << LIME << "0" << backup.exam_number << WHITE << std::endl;
        std::cout << "    CURRENT EX: " << LIME << backup.current_ex->get_name() << RESET << std::endl;
        std::cout << RED << "    " << remaining_time(backup.end_time) << std::endl;
        std::cout << RED << "           left" << std::endl
                  << std::endl;

        std::cout << WHITE << BOLD << "            1" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |" << LIME << BOLD << "  RESTORE EXAM  " << WHITE << BOLD << "|" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl;
        std::cout << WHITE << BOLD << "            2" << RESET << std::endl;
        std::cout << WHITE << BOLD << "     | " << RED << BOLD << " ERASE EXAM" << WHITE << BOLD << "  |" << RESET << BOLD << std::endl
                  << "      \\ ---------- /" << std::endl
                  << std::endl
                  << std::endl;
        std::cout << "            ";

        std::string answer;
        std::cin >> answer;
        while (answer != "1" && answer != "2")
        {
            std::cout << REMOVE_LINE << "            ";
            std::cin >> answer;
        }
        if (answer == "1")
        {
            std::cin.ignore();
            std::cout << std::endl
                      << "   Restoring exam token..." << RESET << std::endl
                      << std::endl;
            this->start_time = backup.get_start_time();
            this->end_time = backup.get_end_time();
            this->exam_number = backup.get_exam_number();
            this->student = backup.student;
            this->level = backup.get_lvl();
            this->current_ex = backup.current_ex;
            this->backup = backup.backup;
            this->level_max = backup.level_max;
            this->level_per_ex = backup.level_per_ex;
            this->level_per_ex_save = backup.level_per_ex_save;
            this->using_cheatcode = backup.using_cheatcode;
        }
        else
        {
            std::cout << "   Exam token deteled" << std::endl;
            std::cin.ignore();
            // delete file and return to menu
            system("rm .system/exam_token/current_token.txt");
            system("clear");
            ask_param();
        }
    }
    else
        ask_param();
}

// ==> Load .settings file into setting_dse bool
void exam::load_settings(void)
{
    std::ifstream file(".system/exam_token/.settings");
    std::string line;
    if (file.is_open())
    {
        file >> setting_dse;
        file >> setting_dcc;
        file >> setting_an;
        file.close();
    }
}

// ==> Save setting_dse bool into .settings file
void exam::save_settings(void)
{
    std::ofstream file(".system/exam_token/.settings");
    if (file.is_open())
    {
        file << setting_dse << std::endl;
        file << setting_dcc << std::endl;
        file << setting_an << std::endl;
        file.close();
    }
}
