#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num_clues;
int difficulty;
int score = 0;
int numberOfWordsGivenOut = 0;
int numberOfTrials = 0;
int index;
int choice;

int play_game(int difficulty);
char *get_word(int difficulty);
int scoringSystem(int numberOfClues);
void print_easy_clues(int wordIndex, char *word);
void print_medium_clues(int wordIndex, char *word);
void print_hard_clues(int wordIndex, char *word);
int verifyAnswer(char *user_answer, char *correct_answer);

// Cluess for Easy Words
char *easy_clues[10][5] = {
    {"Large mammal with a long trunk and tusks",
     "Lives in Africa and Asia",
     "Eats grass, leaves, and bark",
     "Highly intelligent and social",
     "Often depicted in art and culture"},

    {"Musical instrument with strings and a body",
     "Played by strumming or plucking the strings",
     "Has different types like acoustic, electric, and bass",
     "Used in many genres of music, from rock to classical",
     "Popular among hobbyists and professionals alike"},

    {"Meteorological phenomenon consisting of a spectrum of colors",
     "Forms when light is refracted, reflected, and dispersed by water droplets in the air",
     "Has colors like red, orange, yellow, green, blue, indigo, and violet",
     "Symbolizes hope, diversity, and inclusivity",
     "Often used in art, literature, and mythology"},

    {"Human-powered vehicle with two wheels and pedals",
     "Invented in the 19th century",
     "Used for transportation, recreation, and exercise",
     "Has different types like road, mountain, and hybrid",
     "Requires balance and coordination to ride"},

    {"Italian dish consisting of a round flatbread topped with tomato sauce, cheese, and various toppings",
     "Popular around the world",
     "Comes in different styles like Neapolitan, New York, and Chicago",
     "Can be customized with meats, vegetables, and spices",
     "Eaten hot or cold, as a meal or a snack"},

    {"Optical instrument used to observe distant objects",
     "Can magnify and clarify images of stars, planets, and galaxies",
     "Has different types like refracting and reflecting",
     "Used by astronomers, hobbyists, and researchers",
     "Allows us to see the universe beyond our naked eye"},

    {
        "Plant with large, yellow flowers and edible seeds",
        "Native to North and Central America",
        "Grows tall and upright",
        "Symbolizes happiness, loyalty, and longevity",
        "Used in art, food, and medicine",
    },

    {"Inflatable object made of rubber or plastic",
     "Can be filled with air or helium",
     "Comes in different shapes and colors",
     "Used for decoration, entertainment, and transportation",
     "Often seen at parties and events"},

    {"Device used to capture images and record videos",
     "Has lenses, sensors, and controls",
     "Comes in different types like DSLR, mirrorless, and smartphone",
     "Used by photographers, videographers, and enthusiasts",
     "Allows us to preserve and share memories and moments"},

    {"In computer programming, it is a named storage location in the memory that holds a value.",
     "It can hold various types of data such as numbers, strings, and objects.",
     "It can be declared and initialized with a specific value or can be assigned a value later in the program.",
     "It has a scope, which defines where the variable can be accessed in the program.",
     "It can be used to store intermediate results, input from the user, or any other data needed by the program."}};

// Clues for Medium difficulty level
char *medium_clues[10][5] = {
    {"It's a noun used to describe a game or activity that involves solving problems or completing a task.",
     "It can refer to physical jigsaw puzzles, crossword puzzles, or logic puzzles.",
     "It can also refer to a situation that is difficult to understand or solve."
     "It's a word derived from French meaning 'bewilderment.'"},
    {"It's a sea creature with eight arms and a soft body.",
     "It's known for its intelligence and ability to change color to blend in with its surroundings.",
     "It's often used as a symbol of flexibility or adaptability.",
     "It's a word derived from Greek meaning 'eight feet.'"},
    {"It's a mineral that is commonly found in rocks and soils.",
     "It's used in various applications such as watches, electronics, and construction."
     "It's often associated with clarity and durability",
     "It's a word derived from German meaning 'hard'"},
    {"It's a genre of music that originated in African American communities in the late 19th and early 20th centuries.",
     "It's characterized by improvisation, syncopated rhythms, and a variety of musical styles.", "It's often associated with cultural movements such as the Harlem Renaissance.",
     "It's a word with uncertain origins, possibly derived from African American slang."},
    {"It's a noun used to describe an object or keepsake that serves as a reminder of a person, place, or event", "It can be a physical item such as a photograph or ticket stub, or a memory.",
     "It's often associated with nostalgia or sentimentality. It's a word derived from Latin meaning 'to remember.'"},
    {"It 's a gas that makes up approximately 21% of the Earth' s atmosphere.",
     "It's often associated with purity and life-giving properties",
     "It's a word derived from Greek meaning 'acid former.'"},
    {"It's a loose-fitting garment worn for sleeping or lounging.",
     "It can be made from a variety of materials such as cotton or silk.",
     "It's often associated with comfort and relaxation."
     "It ' s a word derived from Hindi meaning 'leg clothing.'"},
    {"It ' s the smallest unit of a digital image that can be displayed on a screen.",
     "It ' s often used in the context of photography, graphic design, and computer graphics.", "It can refer to a physical point of light or a digital representation of a color.", "It ' s a word derived from 'picture element'"},
    {"It's a form of public transportation that runs on tracks underground or above ground.", "It's often used in densely populated urban areas.",
     "It's associated with efficiency and convenience.",
     "It's a word derived from the New York City subway system."},
    {"It's an animal with black and white stripes that is native to Africa.",
     "It's often associated with uniqueness and individuality.",
     "It can also be used metaphorically to describe a situation with alternating or contrasting elements.",
     "It ' s a word derived from Portuguese meaning 'wild ass.'"}};

char *hard_clues[10][4] = {
    {"It' s a term used in art to describe the placement of two contrasting elements together.",
     "It 's also used in literature to create irony or humor.",
     "It can refer to physical placement or a comparison of ideas.",
     "It' s often used to create a sense of tension or surprise."},
    {"It's an adjective used to describe someone who excessively flatters or obeys others.",
     "It's often used in a negative context to suggest insincerity or manipulation.",
     "It can be used to describe a subservient or overly deferential attitude.",
     "It's a word derived from Latin meaning 'to comply with'."},
    {
        "It's a noun used to describe a person who flatters or acts subservient to gain favor or advantage.",
        "It's often used in a negative context to suggest dishonesty or insincerity.",
        "It can be used to describe someone who is willing to sacrifice their own beliefs or values to gain favor.",
        "It's a word derived from Greek meaning 'to show figs.'",
    },
    {
        "It's an adjective used to describe something that is present or found everywhere.",
        "It can refer to physical objects, ideas, or cultural phenomena.",
        "It's often used to describe technology or trends that have become widespread.",
        "It's a word derived from Latin meaning 'everywhere.'",
    },
    {"It's a field of study that focuses on flags and their symbolism.",
     "It involves the study of the history, design, and cultural significance of flags.",
     "It can be used to analyze political or social trends through the study of flags.",
     "It's a word derived from Latin and Greek meaning 'study of flags.'"},
    {"It's a noun used to describe a fear or hatred of strangers or foreigners.",
     "It can manifest in various forms such as racism or nationalism.",
     "It's often used in a negative context to suggest intolerance or prejudice.",
     "It's a word derived from Greek meaning 'fear of strangers.'"},
    {"It's a noun used to describe a person who sails or races yachts.",
     "It can be used to describe a person who is passionate about sailing or boating.",
     "It's often associated with wealth and luxury.",
     "It's a word derived from Middle English meaning 'vessel handler.'"},
    {"It's a branch of chemistry that studies fermentation processes.",
     "It can be used to describe the study of beer or wine making.",
     "It involves the study of microorganisms such as yeast and bacteria.",
     "It's a word derived from Greek meaning 'fermentation.'"},
    {"It's a musical instrument that consists of a series of wooden bars that are struck with mallets.", "It can produce a range of tones and is often used in orchestral music.",
     "It's a word derived from Greek meaning 'wood sound.'",
     "Starts with the letter x"},
    {"It's an adverb used to describe something done without care or planning."
     "It can be used to describe a messy or disorganized situation."
     "It's often used to suggest a lack of intention or purpose."
     "It's a word derived from Middle English meaning 'randomly.'"}};

int main()
{

    printf("Welcome to the  game!\n");
    while (1)
    {
        printf("Choose an option:\n");
        printf("1. Play the game\n");
        printf("2. How to play the game\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
        {
            break;
        }
        else if (choice == 2)
        {
            printf("How to play the game:\n");
            printf("1. Choose a difficulty level.\n");
            printf("2. A word will be selected at random and a clue will be given.\n");
            printf("3. Guess a letter. If it is in the word, it will be revealed.\n");
            printf("4. If you guess the word before running out of tries, you win.\n");
            printf("5. If you run out of tries, you lose.\n");
            continue;
        }
        else if (choice != 1)
        {
            printf("Invalid choice\n");
            continue;
        }

        int difficulty;
        printf("Please enter your name: ");
        char name[100];
        scanf("%s", name);
        while (1)
        {
            printf("Choose a level:\n");
            printf("1. Easy\n");
            printf("2. Medium\n");
            printf("3. Hard\n");
            printf("Enter your choice: ");
            scanf("%d", &difficulty);
            if (difficulty >= 1 && difficulty <= 3)
            {
                play_game(difficulty);
            }
            else
            {
                printf("Invalid difficulty level. Please try again.\n");
            }
        }
    }

    return 0;
}

char *get_word(int difficulty)
{
    char *easy_words[] = {"elephant", "guitar", "rainbow", "bicycle", "pizza", "telescope", "sunflower", "balloon", "variable"};
    char *medium_words[] = {"puzzle", "octopus", "quartz", "jazz", "memento", "oxygen", "pajama", "pixel", "subway", "zebra"};
    char *hard_words[] = {"juxtaposition", "obsequious", "sycophant", "ubiquitous", "vexillology", "xenophobia", "yachtsman", "zymurgy", "xylophone", "haphazardly"};
    int num_words = 10;
    srand(time(NULL));
    index = rand() % num_words;
    char *word;
    if (difficulty == 1)
    {
        word = easy_words[index];
    }
    else if (difficulty == 2)
    {
        word = medium_words[index];
    }
    else
    {
        word = hard_words[index];
    }
    return word;
}

int play_game(int difficulty)
{
    const char *difficultyLevel;
    if (difficulty == 1)
    {
        num_clues = 5;
        difficultyLevel = "Easy";
    }
    else if (difficulty == 2)
    {
        num_clues = 4;
        difficultyLevel = "Medium";
    }
    else if (difficulty == 3)
    {
        num_clues = 3;
        difficultyLevel = "Hard";
    }

    printf("\nYou have selected the %s level and you have %d clues to guess the correct word.\n", difficultyLevel, num_clues);
    char *word = get_word(difficulty);
    if (difficulty == 1)
    {
        print_easy_clues(index, word);
    }
    else if (difficulty == 2)
    {
        print_medium_clues(index, word);
    }
    else if (difficulty == 3)
    {
        print_hard_clues(index, word);
    }
    return 0;
}

void print_easy_clues(int wordIndex, char *word)
{
    int numberOfClues = 5;
    char answer[100];
    int i = 0;
    printf("Clues:\n");
    while (numberOfClues > 0)
    {
        printf("%s \nGuess the word: ", easy_clues[wordIndex][i]);
        numberOfClues--;
        scanf("%s", answer);
        int verification = verifyAnswer(answer, word);
        if (verification == 1)
        {
            printf("Right Guess\n");
            score = scoringSystem(numberOfClues);
            numberOfWordsGivenOut++;
            if (numberOfWordsGivenOut < 3)
            {
                play_game(difficulty);
            }
            else
            {
                difficulty++;
            }

            break;
        }
        i++;
    }
}

void print_medium_clues(int wordIndex, char *word)
{
    int numberOfClues = 4;
    char answer[100];
    int i = 0;
    printf("Clues:\n");
    while (numberOfClues > 0)
    {
        printf("%s \nGuess the word: ", medium_clues[wordIndex][i]);
        numberOfClues--;
        scanf("%s", answer);
        int verification = verifyAnswer(answer, word);
        if (verification == 1)
        {
            printf("Right Guess\n");
            score = scoringSystem(numberOfClues);
            numberOfWordsGivenOut++;
            if (numberOfWordsGivenOut < 3)
            {
                play_game(difficulty);
            }
            else
            {
                difficulty++;
            }

            break;
        }
        i++;
    }
}
void print_hard_clues(int wordIndex, char *word)
{
    int numberOfClues = 3;
    char answer[100];
    int i = 0;
    printf("Clues:\n");
    while (numberOfClues > 0)
    {
        printf("%s \nGuess the word: ", hard_clues[wordIndex][i]);
        numberOfClues--;
        scanf("%s", answer);
        int verification = verifyAnswer(answer, word);
        if (verification == 1)
        {
            printf("Right Guess\n");
            score = scoringSystem(numberOfClues);
            numberOfWordsGivenOut++;
            if (numberOfWordsGivenOut < 3)
            {
                play_game(difficulty);
            }
            else
            {
                printf("End");
            }

            break;
        }
        i++;
    }
}

int verifyAnswer(char *user_answer, char *correct_answer)
{
    if (strcmp(correct_answer, user_answer) == 0)
    {
        printf("\nCorrect answer\n");
        return 1;
    }
    else
    {
        printf("\nWrong answer\n");
        return 0;
    }
}

int scoringSystem(int numberOfClues)
{
    if (numberOfClues == 0)
    {
        score += 0;
    }
    else
    {
        score += 10 / (5 - numberOfClues);
    }
    printf("Score: %d\n", score);
    return score;
}
