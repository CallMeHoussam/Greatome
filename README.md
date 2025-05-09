
# EXAM_MOCK v69 🎓

## All 42 exams auto-correct, to practice.

## PiscineExam
---

### ⚠️ This project is available on MAC and LINUX (the real exam will be on Linux)

---

## Practice for the 42 exam 🏊‍♂️

- [X] New Subjects 
- [X] Subject drawn at random
- [X] Exponential waiting for a correction
- [X] X Hours maximum
- [X] Automatic correction (without internet)
- [X] Traceback available
- [X] Detect infinite loop in your program (ExamRank02)
- [ ] Detect infinite loop in all ExamRank
- [ ] Detect leaks in all exercices

<img width="711" alt="Screenshot 2022-09-06 at 17 00 47" src="https://user-images.githubusercontent.com/55356071/188669367-504411a5-5c62-4848-932e-405c9ee05a45.png">

<img width="711" alt="Screenshot 2022-09-06 at 17 01 15" src="https://user-images.githubusercontent.com/55356071/188669418-04f8bb1b-9cc2-4c07-9d07-5e9c570283b4.png">

# 👓 CHEAT code :

 (sorry don't work in exam at 42)

   **remove_grade_time** : remove grade time between two push

    > The maximum time to complete the exam is only information.
      Here, the exercise can always be corrected even after the time limit.

   **force_success** : force an exercice to success

   **new_ex** : generate a new exercice on the same level


# Launch ExamMocker in ONE COMMAND :

(All commands has to be launch from the 42-EXAM folder)

 bash .system/launch.sh

or 

make 
make
You may need to install g++ and libreadline-dev :

sudo apt-get update
sudo apt-get install g++ libreadline-dev

# 👮‍♀️ RGPD Information :

 Some data may be collected for the sole purpose of improving the service, for example to check if an error is coming from the student and not from the program.
The data that can be collected are :

- The host name of your machine.
- The exam number you choose.
- Name of exercise, fail or success, current assignement and level.

# Contribution by adding more exercises :

You can contribute by adding new exercises very easily with 42_EXAM.

📄 Read this documentation: [Contribution DOC](CONTRIBUTING.md)

🥳 If your contribution is accepted, your name will be listed in the ReadMe as a contributor, thanks!

Contributor : pandaero
              Kuninoto
              ComlanGiovanni

# Disclaimer for 42 staff :

This project is not identical to the proposed exams and does not reflect 42 official exam.
It is only meant to help 42 students to train on some exercises found on Github.
It works simply by doing a DIFF on both versions.
All the subjects have been found on Github. During my schooling at 42, this project helped me to understand a lot of notions like how to host a website, working with javascript, php and others.
This project has been created with the sole purpose of helping students to understand their mistakes and improve themselves.
If It’s not the case, I am ready to make changes and corrections on it, 42_EXAM/GradeMe has only a non-lucrative and educational purpose. It is completely free and open-source.

# Errors
Please before you close the terminal type : finish then type yes
This will help you to avoid errors in next time when you trying it.

Also when you make the program and you facing an error , copy this command in your terminal: 
rm .system/exam_token/current_token.txt 

Then it will works fine 😊

