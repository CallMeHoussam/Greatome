#pragma once
#ifndef EXAM_HPP
#define EXAM_HPP

#include "exercise.hpp"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <iomanip>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include <random>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

// Color and formatting macros
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define LIME "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
#define REMOVE_LINE "\033[2K\r"
#define UNDERLINE "\033[4m"

// Function declarations
std::string generate_unique_id();
std::string current_path(void);
std::string remaining_time(time_t end_time);
std::string lastupdate(time_t end_time);
exercise *randomize_exercise(std::map<int, exercise> list, bool remove_success);
exam restore_data(void);
bool file_exists(std::string path);

void reset_folder(void);
void connexion(void);
void sigc(int sig);
void sigd(void);

int stud_or_swim(void);
int piscine_menu(void);
int stud_menu(void);

class exam
{
public:
    exam(void);
    exam(exam const &src);
    ~exam(void);
    void info(void);
    void ask_param(void);
    void fail_ex(void);
    void success_ex(bool force);
    void explanation(void);
    int get_exam_number(void);
    int get_lvl(void);
    void store_data();
    void up_lvl(void);
    void exam_help();
    std::string get_path(void);
    time_t get_end_time(void);
    time_t get_start_time(void);
    void infovip(void);
    int change_ex(void);
    void exam_prompt(void);
    bool prepare_current_ex(void);
    bool clean_all(void);
    void restore_data(void);
    bool start_new_ex(void);
    exam &operator=(exam const &src);
    std::map<int, exercise> list_dir();
    std::map<int, exercise> list_ex_lvl;
    std::map<int, exercise> lvl_ex;
    exercise *current_ex;
    bool student;
    bool waiting_time;
    int level_max;
    bool changex;

private:
    void set_max_time(void);
    void grademe(void);
    void settings_menu(void);
    void grade_request(bool i);
    void exam_random_show(void);
    void end_exam(void);
    void set_max_lvl(void);
    int stud_menu(void);
    void load_settings(void);
    void save_settings(void);
    int piscine_menu(void);
    int stud_or_swim(void);

    bool setting_dse;
    bool setting_dcc;
    bool setting_an;
    std::string username;

    time_t start_time;
    time_t end_time;

    bool reelmode;
    int level_per_ex_save;
    int time_max;
    int exam_number;
    int using_cheatcode;
    int exam_grade;
    bool vip;
    int level_per_ex;
    int level;
    int failures;
    bool backup;
};

#endif