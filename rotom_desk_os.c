/*=============================================================================
    ROTOM DESK OS
    ---------------------------------------------------------------------------
    File        : rotom_desk_os.c
    Module      : Core System Module
    Author      : Pranav
    Year        : 2026

    Description:
        This file contains system-level functions for Rotom Desk OS,
        including monitoring, configuration, and utility tools.

    Project Features:
        - Multi-utility console OS
        - Media and file manager
        - Number system converter
        - Camera / device tools
        - Custom console UI
        - System commands

    Platform:
        Windows Console / C Language

=============================================================================*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

#define MAX_UNITS 10

// =============================================================
// Global Variable Declaration
// =============================================================

typedef struct
{
    int id;
    char name[30];
    char type[30];
} Pokemon;
typedef struct
{
    char name[50];
    int score;
    int mode;
} HighScore;
typedef struct
{
    char name[20];
    double toBase;
} Unit;
Pokemon list[1025] = {
    {1, "Bulbasaur", "Grass/Poison"},
    {2, "Ivysaur", "Grass/Poison"},
    {3, "Venusaur", "Grass/Poison"},
    {4, "Charmander", "Fire"},
    {5, "Charmeleon", "Fire"},
    {6, "Charizard", "Fire/Flying"},
    {7, "Squirtle", "Water"},
    {8, "Wartortle", "Water"},
    {9, "Blastoise", "Water"},
    {10, "Caterpie", "Bug"},
    {11, "Metapod", "Bug"},
    {12, "Butterfree", "Bug/Flying"},
    {13, "Weedle", "Bug/Poison"},
    {14, "Kakuna", "Bug/Poison"},
    {15, "Beedrill", "Bug/Poison"},
    {16, "Pidgey", "Normal/Flying"},
    {17, "Pidgeotto", "Normal/Flying"},
    {18, "Pidgeot", "Normal/Flying"},
    {19, "Rattata", "Normal"},
    {20, "Raticate", "Normal"},
    {21, "Spearow", "Normal/Flying"},
    {22, "Fearow", "Normal/Flying"},
    {23, "Ekans", "Poison"},
    {24, "Arbok", "Poison"},
    {25, "Pikachu", "Electric"},
    {26, "Raichu", "Electric"},
    {27, "Sandshrew", "Ground"},
    {28, "Sandslash", "Ground"},
    {29, "Nidoran♀", "Poison"},
    {30, "Nidorina", "Poison"},
    {31, "Nidoqueen", "Poison/Ground"},
    {32, "Nidoran♂", "Poison"},
    {33, "Nidorino", "Poison"},
    {34, "Nidoking", "Poison/Ground"},
    {35, "Clefairy", "Fairy"},
    {36, "Clefable", "Fairy"},
    {37, "Vulpix", "Fire"},
    {38, "Ninetales", "Fire"},
    {39, "Jigglypuff", "Normal/Fairy"},
    {40, "Wigglytuff", "Normal/Fairy"},
    {41, "Zubat", "Poison/Flying"},
    {42, "Golbat", "Poison/Flying"},
    {43, "Oddish", "Grass/Poison"},
    {44, "Gloom", "Grass/Poison"},
    {45, "Vileplume", "Grass/Poison"},
    {46, "Paras", "Bug/Grass"},
    {47, "Parasect", "Bug/Grass"},
    {48, "Venonat", "Bug/Poison"},
    {49, "Venomoth", "Bug/Poison"},
    {50, "Diglett", "Ground"},
    {51, "Dugtrio", "Ground"},
    {52, "Meowth", "Normal"},
    {53, "Persian", "Normal"},
    {54, "Psyduck", "Water"},
    {55, "Golduck", "Water"},
    {56, "Mankey", "Fighting"},
    {57, "Primeape", "Fighting"},
    {58, "Growlithe", "Fire"},
    {59, "Arcanine", "Fire"},
    {60, "Poliwag", "Water"},
    {61, "Poliwhirl", "Water"},
    {62, "Poliwrath", "Water/Fighting"},
    {63, "Abra", "Psychic"},
    {64, "Kadabra", "Psychic"},
    {65, "Alakazam", "Psychic"},
    {66, "Machop", "Fighting"},
    {67, "Machoke", "Fighting"},
    {68, "Machamp", "Fighting"},
    {69, "Bellsprout", "Grass/Poison"},
    {70, "Weepinbell", "Grass/Poison"},
    {71, "Victreebel", "Grass/Poison"},
    {72, "Tentacool", "Water/Poison"},
    {73, "Tentacruel", "Water/Poison"},
    {74, "Geodude", "Rock/Ground"},
    {75, "Graveler", "Rock/Ground"},
    {76, "Golem", "Rock/Ground"},
    {77, "Ponyta", "Fire"},
    {78, "Rapidash", "Fire"},
    {79, "Slowpoke", "Water/Psychic"},
    {80, "Slowbro", "Water/Psychic"},
    {81, "Magnemite", "Electric/Steel"},
    {82, "Magneton", "Electric/Steel"},
    {83, "Farfetch'd", "Normal/Flying"},
    {84, "Doduo", "Normal/Flying"},
    {85, "Dodrio", "Normal/Flying"},
    {86, "Seel", "Water"},
    {87, "Dewgong", "Water/Ice"},
    {88, "Grimer", "Poison"},
    {89, "Muk", "Poison"},
    {90, "Shellder", "Water"},
    {91, "Cloyster", "Water/Ice"},
    {92, "Gastly", "Ghost/Poison"},
    {93, "Haunter", "Ghost/Poison"},
    {94, "Gengar", "Ghost/Poison"},
    {95, "Onix", "Rock/Ground"},
    {96, "Drowzee", "Psychic"},
    {97, "Hypno", "Psychic"},
    {98, "Krabby", "Water"},
    {99, "Kingler", "Water"},
    {100, "Voltorb", "Electric"},
    {101, "Electrode", "Electric"},
    {102, "Exeggcute", "Grass/Psychic"},
    {103, "Exeggutor", "Grass/Psychic"},
    {104, "Cubone", "Ground"},
    {105, "Marowak", "Ground"},
    {106, "Hitmonlee", "Fighting"},
    {107, "Hitmonchan", "Fighting"},
    {108, "Lickitung", "Normal"},
    {109, "Koffing", "Poison"},
    {110, "Weezing", "Poison"},
    {111, "Rhyhorn", "Ground/Rock"},
    {112, "Rhydon", "Ground/Rock"},
    {113, "Chansey", "Normal"},
    {114, "Tangela", "Grass"},
    {115, "Kangaskhan", "Normal"},
    {116, "Horsea", "Water"},
    {117, "Seadra", "Water"},
    {118, "Goldeen", "Water"},
    {119, "Seaking", "Water"},
    {120, "Staryu", "Water"},
    {121, "Starmie", "Water/Psychic"},
    {122, "Mr. Mime", "Psychic/Fairy"},
    {123, "Scyther", "Bug/Flying"},
    {124, "Jynx", "Ice/Psychic"},
    {125, "Electabuzz", "Electric"},
    {126, "Magmar", "Fire"},
    {127, "Pinsir", "Bug"},
    {128, "Tauros", "Normal"},
    {129, "Magikarp", "Water"},
    {130, "Gyarados", "Water/Flying"},
    {131, "Lapras", "Water/Ice"},
    {132, "Ditto", "Normal"},
    {133, "Eevee", "Normal"},
    {134, "Vaporeon", "Water"},
    {135, "Jolteon", "Electric"},
    {136, "Flareon", "Fire"},
    {137, "Porygon", "Normal"},
    {138, "Omanyte", "Rock/Water"},
    {139, "Omastar", "Rock/Water"},
    {140, "Kabuto", "Rock/Water"},
    {141, "Kabutops", "Rock/Water"},
    {142, "Aerodactyl", "Rock/Flying"},
    {143, "Snorlax", "Normal"},
    {144, "Articuno", "Ice/Flying"},
    {145, "Zapdos", "Electric/Flying"},
    {146, "Moltres", "Fire/Flying"},
    {147, "Dratini", "Dragon"},
    {148, "Dragonair", "Dragon"},
    {149, "Dragonite", "Dragon/Flying"},
    {150, "Mewtwo", "Psychic"},
    {151, "Mew", "Psychic"},
    {152, "Chikorita", "Grass"},
    {153, "Bayleef", "Grass"},
    {154, "Meganium", "Grass"},
    {155, "Cyndaquil", "Fire"},
    {156, "Quilava", "Fire"},
    {157, "Typhlosion", "Fire"},
    {158, "Totodile", "Water"},
    {159, "Croconaw", "Water"},
    {160, "Feraligatr", "Water"},
    {161, "Sentret", "Normal"},
    {162, "Furret", "Normal"},
    {163, "Hoothoot", "Normal/Flying"},
    {164, "Noctowl", "Normal/Flying"},
    {165, "Ledyba", "Bug/Flying"},
    {166, "Ledian", "Bug/Flying"},
    {167, "Spinarak", "Bug/Poison"},
    {168, "Ariados", "Bug/Poison"},
    {169, "Crobat", "Poison/Flying"},
    {170, "Chinchou", "Water/Electric"},
    {171, "Lanturn", "Water/Electric"},
    {172, "Pichu", "Electric"},
    {173, "Cleffa", "Fairy"},
    {174, "Igglybuff", "Normal/Fairy"},
    {175, "Togepi", "Fairy"},
    {176, "Togetic", "Fairy/Flying"},
    {177, "Natu", "Psychic/Flying"},
    {178, "Xatu", "Psychic/Flying"},
    {179, "Mareep", "Electric"},
    {180, "Flaaffy", "Electric"},
    {181, "Ampharos", "Electric"},
    {182, "Bellossom", "Grass"},
    {183, "Marill", "Water/Fairy"},
    {184, "Azumarill", "Water/Fairy"},
    {185, "Sudowoodo", "Rock"},
    {186, "Politoed", "Water"},
    {187, "Hoppip", "Grass/Flying"},
    {188, "Skiploom", "Grass/Flying"},
    {189, "Jumpluff", "Grass/Flying"},
    {190, "Aipom", "Normal"},
    {191, "Sunkern", "Grass"},
    {192, "Sunflora", "Grass"},
    {193, "Yanma", "Bug/Flying"},
    {194, "Wooper", "Water/Ground"},
    {195, "Quagsire", "Water/Ground"},
    {196, "Espeon", "Psychic"},
    {197, "Umbreon", "Dark"},
    {198, "Murkrow", "Dark/Flying"},
    {199, "Slowking", "Water/Psychic"},
    {200, "Misdreavus", "Ghost"},
    {201, "Unown", "Psychic"},
    {202, "Wobbuffet", "Psychic"},
    {203, "Girafarig", "Normal/Psychic"},
    {204, "Pineco", "Bug"},
    {205, "Forretress", "Bug/Steel"},
    {206, "Dunsparce", "Normal"},
    {207, "Gligar", "Ground/Flying"},
    {208, "Steelix", "Steel/Ground"},
    {209, "Snubbull", "Fairy"},
    {210, "Granbull", "Fairy"},
    {211, "Qwilfish", "Water/Poison"},
    {212, "Scizor", "Bug/Steel"},
    {213, "Shuckle", "Bug/Rock"},
    {214, "Heracross", "Bug/Fighting"},
    {215, "Sneasel", "Dark/Ice"},
    {216, "Teddiursa", "Normal"},
    {217, "Ursaring", "Normal"},
    {218, "Slugma", "Fire"},
    {219, "Magcargo", "Fire/Rock"},
    {220, "Swinub", "Ice/Ground"},
    {221, "Piloswine", "Ice/Ground"},
    {222, "Corsola", "Water/Rock"},
    {223, "Remoraid", "Water"},
    {224, "Octillery", "Water"},
    {225, "Delibird", "Ice/Flying"},
    {226, "Mantine", "Water/Flying"},
    {227, "Skarmory", "Steel/Flying"},
    {228, "Houndour", "Dark/Fire"},
    {229, "Houndoom", "Dark/Fire"},
    {230, "Kingdra", "Water/Dragon"},
    {231, "Phanpy", "Ground"},
    {232, "Donphan", "Ground"},
    {233, "Porygon2", "Normal"},
    {234, "Stantler", "Normal"},
    {235, "Smeargle", "Normal"},
    {236, "Tyrogue", "Fighting"},
    {237, "Hitmontop", "Fighting"},
    {238, "Smoochum", "Ice/Psychic"},
    {239, "Elekid", "Electric"},
    {240, "Magby", "Fire"},
    {241, "Miltank", "Normal"},
    {242, "Blissey", "Normal"},
    {243, "Raikou", "Electric"},
    {244, "Entei", "Fire"},
    {245, "Suicune", "Water"},
    {246, "Larvitar", "Rock/Ground"},
    {247, "Pupitar", "Rock/Ground"},
    {248, "Tyranitar", "Rock/Dark"},
    {249, "Lugia", "Psychic/Flying"},
    {250, "Ho-oh", "Fire/Flying"},
    {251, "Celebi", "Psychic/Grass"},
    {252, "Treecko", "Grass"},
    {253, "Grovyle", "Grass"},
    {254, "Sceptile", "Grass"},
    {255, "Torchic", "Fire"},
    {256, "Combusken", "Fire/Fighting"},
    {257, "Blaziken", "Fire/Fighting"},
    {258, "Mudkip", "Water"},
    {259, "Marshtomp", "Water/Ground"},
    {260, "Swampert", "Water/Ground"},
    {261, "Poochyena", "Dark"},
    {262, "Mightyena", "Dark"},
    {263, "Zigzagoon", "Normal"},
    {264, "Linoone", "Normal"},
    {265, "Wurmple", "Bug"},
    {266, "Silcoon", "Bug"},
    {267, "Beautifly", "Bug/Flying"},
    {268, "Cascoon", "Bug"},
    {269, "Dustox", "Bug/Poison"},
    {270, "Lotad", "Water/Grass"},
    {271, "Lombre", "Water/Grass"},
    {272, "Ludicolo", "Water/Grass"},
    {273, "Seedot", "Grass"},
    {274, "Nuzleaf", "Grass/Dark"},
    {275, "Shiftry", "Grass/Dark"},
    {276, "Taillow", "Normal/Flying"},
    {277, "Swellow", "Normal/Flying"},
    {278, "Wingull", "Water/Flying"},
    {279, "Pelipper", "Water/Flying"},
    {280, "Ralts", "Psychic/Fairy"},
    {281, "Kirlia", "Psychic/Fairy"},
    {282, "Gardevoir", "Psychic/Fairy"},
    {283, "Surskit", "Bug/Water"},
    {284, "Masquerain", "Bug/Flying"},
    {285, "Shroomish", "Grass"},
    {286, "Breloom", "Grass/Fighting"},
    {287, "Slakoth", "Normal"},
    {288, "Vigoroth", "Normal"},
    {289, "Slaking", "Normal"},
    {290, "Nincada", "Bug/Ground"},
    {291, "Ninjask", "Bug/Flying"},
    {292, "Shedinja", "Bug/Ghost"},
    {293, "Whismur", "Normal"},
    {294, "Loudred", "Normal"},
    {295, "Exploud", "Normal"},
    {296, "Makuhita", "Fighting"},
    {297, "Hariyama", "Fighting"},
    {298, "Azurill", "Normal/Fairy"},
    {299, "Nosepass", "Rock"},
    {300, "Skitty", "Normal"},
    {301, "Delcatty", "Normal"},
    {302, "Sableye", "Dark/Ghost"},
    {303, "Mawile", "Steel/Fairy"},
    {304, "Aron", "Steel/Rock"},
    {305, "Lairon", "Steel/Rock"},
    {306, "Aggron", "Steel/Rock"},
    {307, "Meditite", "Fighting/Psychic"},
    {308, "Medicham", "Fighting/Psychic"},
    {309, "Electrike", "Electric"},
    {310, "Manectric", "Electric"},
    {311, "Plusle", "Electric"},
    {312, "Minun", "Electric"},
    {313, "Volbeat", "Bug"},
    {314, "Illumise", "Bug"},
    {315, "Roselia", "Grass/Poison"},
    {316, "Gulpin", "Poison"},
    {317, "Swalot", "Poison"},
    {318, "Carvanha", "Water/Dark"},
    {319, "Sharpedo", "Water/Dark"},
    {320, "Wailmer", "Water"},
    {321, "Wailord", "Water"},
    {322, "Numel", "Fire/Ground"},
    {323, "Camerupt", "Fire/Ground"},
    {324, "Torkoal", "Fire"},
    {325, "Spoink", "Psychic"},
    {326, "Grumpig", "Psychic"},
    {327, "Spinda", "Normal"},
    {328, "Trapinch", "Ground"},
    {329, "Vibrava", "Ground/Dragon"},
    {330, "Flygon", "Ground/Dragon"},
    {331, "Cacnea", "Grass"},
    {332, "Cacturne", "Grass/Dark"},
    {333, "Swablu", "Normal/Flying"},
    {334, "Altaria", "Dragon/Flying"},
    {335, "Zangoose", "Normal"},
    {336, "Seviper", "Poison"},
    {337, "Lunatone", "Rock/Psychic"},
    {338, "Solrock", "Rock/Psychic"},
    {339, "Barboach", "Water/Ground"},
    {340, "Whiscash", "Water/Ground"},
    {341, "Corphish", "Water"},
    {342, "Crawdaunt", "Water/Dark"},
    {343, "Baltoy", "Ground/Psychic"},
    {344, "Claydol", "Ground/Psychic"},
    {345, "Lileep", "Rock/Grass"},
    {346, "Cradily", "Rock/Grass"},
    {347, "Anorith", "Rock/Bug"},
    {348, "Armaldo", "Rock/Bug"},
    {349, "Feebas", "Water"},
    {350, "Milotic", "Water"},
    {351, "Castform", "Normal"},
    {352, "Kecleon", "Normal"},
    {353, "Shuppet", "Ghost"},
    {354, "Banette", "Ghost"},
    {355, "Duskull", "Ghost"},
    {356, "Dusclops", "Ghost"},
    {357, "Tropius", "Grass/Flying"},
    {358, "Chimecho", "Psychic"},
    {359, "Absol", "Dark"},
    {360, "Wynaut", "Psychic"},
    {361, "Snorunt", "Ice"},
    {362, "Glalie", "Ice"},
    {363, "Spheal", "Ice/Water"},
    {364, "Sealeo", "Ice/Water"},
    {365, "Walrein", "Ice/Water"},
    {366, "Clamperl", "Water"},
    {367, "Huntail", "Water"},
    {368, "Gorebyss", "Water"},
    {369, "Relicanth", "Water/Rock"},
    {370, "Luvdisc", "Water"},
    {371, "Bagon", "Dragon"},
    {372, "Shelgon", "Dragon"},
    {373, "Salamence", "Dragon/Flying"},
    {374, "Beldum", "Steel/Psychic"},
    {375, "Metang", "Steel/Psychic"},
    {376, "Metagross", "Steel/Psychic"},
    {377, "Regirock", "Rock"},
    {378, "Regice", "Ice"},
    {379, "Registeel", "Steel"},
    {380, "Latias", "Dragon/Psychic"},
    {381, "Latios", "Dragon/Psychic"},
    {382, "Kyogre", "Water"},
    {383, "Groudon", "Ground"},
    {384, "Rayquaza", "Dragon/Flying"},
    {385, "Jirachi", "Steel/Psychic"},
    {386, "Deoxys", "Psychic"},
    {387, "Turtwig", "Grass"},
    {388, "Grotle", "Grass"},
    {389, "Torterra", "Grass/Ground"},
    {390, "Chimchar", "Fire"},
    {391, "Monferno", "Fire/Fighting"},
    {392, "Infernape", "Fire/Fighting"},
    {393, "Piplup", "Water"},
    {394, "Prinplup", "Water"},
    {395, "Empoleon", "Water/Steel"},
    {396, "Starly", "Normal/Flying"},
    {397, "Staravia", "Normal/Flying"},
    {398, "Staraptor", "Normal/Flying"},
    {399, "Bidoof", "Normal"},
    {400, "Bibarel", "Normal/Water"},
    {401, "Kricketot", "Bug"},
    {402, "Kricketune", "Bug"},
    {403, "Shinx", "Electric"},
    {404, "Luxio", "Electric"},
    {405, "Luxray", "Electric"},
    {406, "Budew", "Grass/Poison"},
    {407, "Roserade", "Grass/Poison"},
    {408, "Cranidos", "Rock"},
    {409, "Rampardos", "Rock"},
    {410, "Shieldon", "Rock/Steel"},
    {411, "Bastiodon", "Rock/Steel"},
    {412, "Burmy", "Bug"},
    {413, "Wormadam", "Bug/Grass"},
    {414, "Mothim", "Bug/Flying"},
    {415, "Combee", "Bug/Flying"},
    {416, "Vespiquen", "Bug/Flying"},
    {417, "Pachirisu", "Electric"},
    {418, "Buizel", "Water"},
    {419, "Floatzel", "Water"},
    {420, "Cherubi", "Grass"},
    {421, "Cherrim", "Grass"},
    {422, "Shellos", "Water"},
    {423, "Gastrodon", "Water/Ground"},
    {424, "Ambipom", "Normal"},
    {425, "Drifloon", "Ghost/Flying"},
    {426, "Drifblim", "Ghost/Flying"},
    {427, "Buneary", "Normal"},
    {428, "Lopunny", "Normal"},
    {429, "Mismagius", "Ghost"},
    {430, "Honchkrow", "Dark/Flying"},
    {431, "Glameow", "Normal"},
    {432, "Purugly", "Normal"},
    {433, "Chingling", "Psychic"},
    {434, "Stunky", "Poison/Dark"},
    {435, "Skuntank", "Poison/Dark"},
    {436, "Bronzor", "Steel/Psychic"},
    {437, "Bronzong", "Steel/Psychic"},
    {438, "Bonsly", "Rock"},
    {439, "Mime Jr.", "Psychic/Fairy"},
    {440, "Happiny", "Normal"},
    {441, "Chatot", "Normal/Flying"},
    {442, "Spiritomb", "Ghost/Dark"},
    {443, "Gible", "Dragon/Ground"},
    {444, "Gabite", "Dragon/Ground"},
    {445, "Garchomp", "Dragon/Ground"},
    {446, "Munchlax", "Normal"},
    {447, "Riolu", "Fighting"},
    {448, "Lucario", "Fighting/Steel"},
    {449, "Hippopotas", "Ground"},
    {450, "Hippowdon", "Ground"},
    {451, "Skorupi", "Poison/Bug"},
    {452, "Drapion", "Poison/Dark"},
    {453, "Croagunk", "Poison/Fighting"},
    {454, "Toxicroak", "Poison/Fighting"},
    {455, "Carnivine", "Grass"},
    {456, "Finneon", "Water"},
    {457, "Lumineon", "Water"},
    {458, "Mantyke", "Water/Flying"},
    {459, "Snover", "Grass/Ice"},
    {460, "Abomasnow", "Grass/Ice"},
    {461, "Weavile", "Dark/Ice"},
    {462, "Magnezone", "Electric/Steel"},
    {463, "Lickilicky", "Normal"},
    {464, "Rhyperior", "Ground/Rock"},
    {465, "Tangrowth", "Grass"},
    {466, "Electivire", "Electric"},
    {467, "Magmortar", "Fire"},
    {468, "Togekiss", "Fairy/Flying"},
    {469, "Yanmega", "Bug/Flying"},
    {470, "Leafeon", "Grass"},
    {471, "Glaceon", "Ice"},
    {472, "Gliscor", "Ground/Flying"},
    {473, "Mamoswine", "Ice/Ground"},
    {474, "Porygon-Z", "Normal"},
    {475, "Gallade", "Psychic/Fighting"},
    {476, "Probopass", "Rock/Steel"},
    {477, "Dusknoir", "Ghost"},
    {478, "Froslass", "Ice/Ghost"},
    {479, "Rotom", "Electric/Ghost"},
    {480, "Uxie", "Psychic"},
    {481, "Mesprit", "Psychic"},
    {482, "Azelf", "Psychic"},
    {483, "Dialga", "Steel/Dragon"},
    {484, "Palkia", "Water/Dragon"},
    {485, "Heatran", "Fire/Steel"},
    {486, "Regigigas", "Normal"},
    {487, "Giratina", "Ghost/Dragon"},
    {488, "Cresselia", "Psychic"},
    {489, "Phione", "Water"},
    {490, "Manaphy", "Water"},
    {491, "Darkrai", "Dark"},
    {492, "Shaymin", "Grass"},
    {493, "Arceus", "Normal"},
    {494, "Victini", "Psychic/Fire"},
    {495, "Snivy", "Grass"},
    {496, "Servine", "Grass"},
    {497, "Serperior", "Grass"},
    {498, "Tepig", "Fire"},
    {499, "Pignite", "Fire/Fighting"},
    {500, "Emboar", "Fire/Fighting"},
    {501, "Oshawott", "Water"},
    {502, "Dewott", "Water"},
    {503, "Samurott", "Water"},
    {504, "Patrat", "Normal"},
    {505, "Watchog", "Normal"},
    {506, "Lillipup", "Normal"},
    {507, "Herdier", "Normal"},
    {508, "Stoutland", "Normal"},
    {509, "Purrloin", "Dark"},
    {510, "Liepard", "Dark"},
    {511, "Pansage", "Grass"},
    {512, "Simisage", "Grass"},
    {513, "Pansear", "Fire"},
    {514, "Simisear", "Fire"},
    {515, "Panpour", "Water"},
    {516, "Simipour", "Water"},
    {517, "Munna", "Psychic"},
    {518, "Musharna", "Psychic"},
    {519, "Pidove", "Normal/Flying"},
    {520, "Tranquill", "Normal/Flying"},
    {521, "Unfezant", "Normal/Flying"},
    {522, "Blitzle", "Electric"},
    {523, "Zebstrika", "Electric"},
    {524, "Roggenrola", "Rock"},
    {525, "Boldore", "Rock"},
    {526, "Gigalith", "Rock"},
    {527, "Woobat", "Psychic/Flying"},
    {528, "Swoobat", "Psychic/Flying"},
    {529, "Drilbur", "Ground"},
    {530, "Excadrill", "Ground/Steel"},
    {531, "Audino", "Normal"},
    {532, "Timburr", "Fighting"},
    {533, "Gurdurr", "Fighting"},
    {534, "Conkeldurr", "Fighting"},
    {535, "Tympole", "Water"},
    {536, "Palpitoad", "Water/Ground"},
    {537, "Seismitoad", "Water/Ground"},
    {538, "Throh", "Fighting"},
    {539, "Sawk", "Fighting"},
    {540, "Sewaddle", "Bug/Grass"},
    {541, "Swadloon", "Bug/Grass"},
    {542, "Leavanny", "Bug/Grass"},
    {543, "Venipede", "Bug/Poison"},
    {544, "Whirlipede", "Bug/Poison"},
    {545, "Scolipede", "Bug/Poison"},
    {546, "Cottonee", "Grass/Fairy"},
    {547, "Whimsicott", "Grass/Fairy"},
    {548, "Petilil", "Grass"},
    {549, "Lilligant", "Grass"},
    {550, "Basculin", "Water"},
    {551, "Sandile", "Ground/Dark"},
    {552, "Krokorok", "Ground/Dark"},
    {553, "Krookodile", "Ground/Dark"},
    {554, "Darumaka", "Fire"},
    {555, "Darmanitan", "Fire"},
    {556, "Maractus", "Grass"},
    {557, "Dwebble", "Bug/Rock"},
    {558, "Crustle", "Bug/Rock"},
    {559, "Scraggy", "Dark/Fighting"},
    {560, "Scrafty", "Dark/Fighting"},
    {561, "Sigilyph", "Psychic/Flying"},
    {562, "Yamask", "Ghost"},
    {563, "Cofagrigus", "Ghost"},
    {564, "Tirtouga", "Water/Rock"},
    {565, "Carracosta", "Water/Rock"},
    {566, "Archen", "Rock/Flying"},
    {567, "Archeops", "Rock/Flying"},
    {568, "Trubbish", "Poison"},
    {569, "Garbodor", "Poison"},
    {570, "Zorua", "Dark"},
    {571, "Zoroark", "Dark"},
    {572, "Minccino", "Normal"},
    {573, "Cinccino", "Normal"},
    {574, "Gothita", "Psychic"},
    {575, "Gothorita", "Psychic"},
    {576, "Gothitelle", "Psychic"},
    {577, "Solosis", "Psychic"},
    {578, "Duosion", "Psychic"},
    {579, "Reuniclus", "Psychic"},
    {580, "Ducklett", "Water/Flying"},
    {581, "Swanna", "Water/Flying"},
    {582, "Vanillite", "Ice"},
    {583, "Vanillish", "Ice"},
    {584, "Vanilluxe", "Ice"},
    {585, "Deerling", "Normal/Grass"},
    {586, "Sawsbuck", "Normal/Grass"},
    {587, "Emolga", "Electric/Flying"},
    {588, "Karrablast", "Bug"},
    {589, "Escavalier", "Bug/Steel"},
    {590, "Foongus", "Grass/Poison"},
    {591, "Amoonguss", "Grass/Poison"},
    {592, "Frillish", "Water/Ghost"},
    {593, "Jellicent", "Water/Ghost"},
    {594, "Alomomola", "Water"},
    {595, "Joltik", "Bug/Electric"},
    {596, "Galvantula", "Bug/Electric"},
    {597, "Ferroseed", "Grass/Steel"},
    {598, "Ferrothorn", "Grass/Steel"},
    {599, "Klink", "Steel"},
    {600, "Klang", "Steel"},
    {601, "Klinklang", "Steel"},
    {602, "Tynamo", "Electric"},
    {603, "Eelektrik", "Electric"},
    {604, "Eelektross", "Electric"},
    {605, "Elgyem", "Psychic"},
    {606, "Beheeyem", "Psychic"},
    {607, "Litwick", "Ghost/Fire"},
    {608, "Lampent", "Ghost/Fire"},
    {609, "Chandelure", "Ghost/Fire"},
    {610, "Axew", "Dragon"},
    {611, "Fraxure", "Dragon"},
    {612, "Haxorus", "Dragon"},
    {613, "Cubchoo", "Ice"},
    {614, "Beartic", "Ice"},
    {615, "Cryogonal", "Ice"},
    {616, "Shelmet", "Bug"},
    {617, "Accelgor", "Bug"},
    {618, "Stunfisk", "Ground/Electric"},
    {619, "Mienfoo", "Fighting"},
    {620, "Mienshao", "Fighting"},
    {621, "Druddigon", "Dragon"},
    {622, "Golett", "Ground/Ghost"},
    {623, "Golurk", "Ground/Ghost"},
    {624, "Pawniard", "Dark/Steel"},
    {625, "Bisharp", "Dark/Steel"},
    {626, "Bouffalant", "Normal"},
    {627, "Rufflet", "Normal/Flying"},
    {628, "Braviary", "Normal/Flying"},
    {629, "Vullaby", "Dark/Flying"},
    {630, "Mandibuzz", "Dark/Flying"},
    {631, "Heatmor", "Fire"},
    {632, "Durant", "Bug/Steel"},
    {633, "Deino", "Dark/Dragon"},
    {634, "Zweilous", "Dark/Dragon"},
    {635, "Hydreigon", "Dark/Dragon"},
    {636, "Larvesta", "Bug/Fire"},
    {637, "Volcarona", "Bug/Fire"},
    {638, "Cobalion", "Steel/Fighting"},
    {639, "Terrakion", "Rock/Fighting"},
    {640, "Virizion", "Grass/Fighting"},
    {641, "Tornadus", "Flying"},
    {642, "Thundurus", "Electric/Flying"},
    {643, "Reshiram", "Dragon/Fire"},
    {644, "Zekrom", "Dragon/Electric"},
    {645, "Landorus", "Ground/Flying"},
    {646, "Kyurem", "Dragon/Ice"},
    {647, "Keldeo", "Water/Fighting"},
    {648, "Meloetta", "Normal/Psychic"},
    {649, "Genesect", "Bug/Steel"},
    {650, "Chespin", "Grass"},
    {651, "Quilladin", "Grass"},
    {652, "Chesnaught", "Grass/Fighting"},
    {653, "Fennekin", "Fire"},
    {654, "Braixen", "Fire"},
    {655, "Delphox", "Fire/Psychic"},
    {656, "Froakie", "Water"},
    {657, "Frogadier", "Water"},
    {658, "Greninja", "Water/Dark"},
    {659, "Bunnelby", "Normal"},
    {660, "Diggersby", "Normal/Ground"},
    {661, "Fletchling", "Normal/Flying"},
    {662, "Fletchinder", "Fire/Flying"},
    {663, "Talonflame", "Fire/Flying"},
    {664, "Scatterbug", "Bug"},
    {665, "Spewpa", "Bug"},
    {666, "Vivillon", "Bug/Flying"},
    {667, "Litleo", "Fire/Normal"},
    {668, "Pyroar", "Fire/Normal"},
    {669, "Flabébé", "Fairy"},
    {670, "Floette", "Fairy"},
    {671, "Florges", "Fairy"},
    {672, "Skiddo", "Grass"},
    {673, "Gogoat", "Grass"},
    {674, "Pancham", "Fighting"},
    {675, "Pangoro", "Fighting/Dark"},
    {676, "Furfrou", "Normal"},
    {677, "Espurr", "Psychic"},
    {678, "Meowstic", "Psychic"},
    {679, "Honedge", "Steel/Ghost"},
    {680, "Doublade", "Steel/Ghost"},
    {681, "Aegislash", "Steel/Ghost"},
    {682, "Spritzee", "Fairy"},
    {683, "Aromatisse", "Fairy"},
    {684, "Swirlix", "Fairy"},
    {685, "Slurpuff", "Fairy"},
    {686, "Inkay", "Dark/Psychic"},
    {687, "Malamar", "Dark/Psychic"},
    {688, "Binacle", "Rock/Water"},
    {689, "Barbaracle", "Rock/Water"},
    {690, "Skrelp", "Poison/Water"},
    {691, "Dragalge", "Poison/Dragon"},
    {692, "Clauncher", "Water"},
    {693, "Clawitzer", "Water"},
    {694, "Helioptile", "Electric/Normal"},
    {695, "Heliolisk", "Electric/Normal"},
    {696, "Tyrunt", "Rock/Dragon"},
    {697, "Tyrantrum", "Rock/Dragon"},
    {698, "Amaura", "Rock/Ice"},
    {699, "Aurorus", "Rock/Ice"},
    {700, "Sylveon", "Fairy"},
    {701, "Hawlucha", "Fighting/Flying"},
    {702, "Dedenne", "Electric/Fairy"},
    {703, "Carbink", "Rock/Fairy"},
    {704, "Goomy", "Dragon"},
    {705, "Sliggoo", "Dragon"},
    {706, "Goodra", "Dragon"},
    {707, "Klefki", "Steel/Fairy"},
    {708, "Phantump", "Ghost/Grass"},
    {709, "Trevenant", "Ghost/Grass"},
    {710, "Pumpkaboo", "Ghost/Grass"},
    {711, "Gourgeist", "Ghost/Grass"},
    {712, "Bergmite", "Ice"},
    {713, "Avalugg", "Ice"},
    {714, "Noibat", "Flying/Dragon"},
    {715, "Noivern", "Flying/Dragon"},
    {716, "Xerneas", "Fairy"},
    {717, "Yveltal", "Dark/Flying"},
    {718, "Zygarde", "Dragon/Ground"},
    {719, "Diancie", "Rock/Fairy"},
    {720, "Hoopa", "Psychic/Ghost"},
    {721, "Volcanion", "Fire/Water"},
    {722, "Rowlet", "Grass/Flying"},
    {723, "Dartrix", "Grass/Flying"},
    {724, "Decidueye", "Grass/Ghost"},
    {725, "Litten", "Fire"},
    {726, "Torracat", "Fire"},
    {727, "Incineroar", "Fire/Dark"},
    {728, "Popplio", "Water"},
    {729, "Brionne", "Water"},
    {730, "Primarina", "Water/Fairy"},
    {731, "Pikipek", "Normal/Flying"},
    {732, "Trumbeak", "Normal/Flying"},
    {733, "Toucannon", "Normal/Flying"},
    {734, "Yungoos", "Normal"},
    {735, "Gumshoos", "Normal"},
    {736, "Grubbin", "Bug"},
    {737, "Charjabug", "Bug/Electric"},
    {738, "Vikavolt", "Bug/Electric"},
    {739, "Crabrawler", "Fighting"},
    {740, "Crabominable", "Fighting/Ice"},
    {741, "Oricorio", "Fire/Flying"},
    {742, "Cutiefly", "Bug/Fairy"},
    {743, "Ribombee", "Bug/Fairy"},
    {744, "Rockruff", "Rock"},
    {745, "Lycanroc", "Rock"},
    {746, "Wishiwashi", "Water"},
    {747, "Mareanie", "Poison/Water"},
    {748, "Toxapex", "Poison/Water"},
    {749, "Mudbray", "Ground"},
    {750, "Mudsdale", "Ground"},
    {751, "Dewpider", "Water/Bug"},
    {752, "Araquanid", "Water/Bug"},
    {753, "Fomantis", "Grass"},
    {754, "Lurantis", "Grass"},
    {755, "Morelull", "Grass/Fairy"},
    {756, "Shiinotic", "Grass/Fairy"},
    {757, "Salandit", "Poison/Fire"},
    {758, "Salazzle", "Poison/Fire"},
    {759, "Stufful", "Normal/Fighting"},
    {760, "Bewear", "Normal/Fighting"},
    {761, "Bounsweet", "Grass"},
    {762, "Steenee", "Grass"},
    {763, "Tsareena", "Grass"},
    {764, "Comfey", "Fairy"},
    {765, "Oranguru", "Normal/Psychic"},
    {766, "Passimian", "Fighting"},
    {767, "Wimpod", "Bug/Water"},
    {768, "Golisopod", "Bug/Water"},
    {769, "Sandygast", "Ghost/Ground"},
    {770, "Palossand", "Ghost/Ground"},
    {771, "Pyukumuku", "Water"},
    {772, "Type: Null", "Normal"},
    {773, "Silvally", "Normal"},
    {774, "Minior", "Rock/Flying"},
    {775, "Komala", "Normal"},
    {776, "Turtonator", "Fire/Dragon"},
    {777, "Togedemaru", "Electric/Steel"},
    {778, "Mimikyu", "Ghost/Fairy"},
    {779, "Bruxish", "Water/Psychic"},
    {780, "Drampa", "Normal/Dragon"},
    {781, "Dhelmise", "Ghost/Grass"},
    {782, "Jangmo-o", "Dragon"},
    {783, "Hakamo-o", "Dragon/Fighting"},
    {784, "Kommo-o", "Dragon/Fighting"},
    {785, "Tapu Koko", "Electric/Fairy"},
    {786, "Tapu Lele", "Psychic/Fairy"},
    {787, "Tapu Bulu", "Grass/Fairy"},
    {788, "Tapu Fini", "Water/Fairy"},
    {789, "Cosmog", "Psychic"},
    {790, "Cosmoem", "Psychic"},
    {791, "Solgaleo", "Psychic/Steel"},
    {792, "Lunala", "Psychic/Ghost"},
    {793, "Nihilego", "Rock/Poison"},
    {794, "Buzzwole", "Bug/Fighting"},
    {795, "Pheromosa", "Bug/Fighting"},
    {796, "Xurkitree", "Electric"},
    {797, "Celesteela", "Steel/Flying"},
    {798, "Kartana", "Grass/Steel"},
    {799, "Guzzlord", "Dark/Dragon"},
    {800, "Necrozma", "Psychic"},
    {801, "Magearna", "Steel/Fairy"},
    {802, "Marshadow", "Fighting/Ghost"},
    {803, "Poipole", "Poison"},
    {804, "Naganadel", "Poison/Dragon"},
    {805, "Stakataka", "Rock/Steel"},
    {806, "Blacephalon", "Fire/Ghost"},
    {807, "Zeraora", "Electric"},
    {808, "Meltan", "Steel"},
    {809, "Melmetal", "Steel"},
    {810, "Grookey", "Grass"},
    {811, "Thwackey", "Grass"},
    {812, "Rillaboom", "Grass"},
    {813, "Scorbunny", "Fire"},
    {814, "Raboot", "Fire"},
    {815, "Cinderace", "Fire"},
    {816, "Sobble", "Water"},
    {817, "Drizzile", "Water"},
    {818, "Inteleon", "Water"},
    {819, "Skwovet", "Normal"},
    {820, "Greedent", "Normal"},
    {821, "Rookidee", "Flying"},
    {822, "Corvisquire", "Flying"},
    {823, "Corviknight", "Flying/Steel"},
    {824, "Blipbug", "Bug"},
    {825, "Dottler", "Bug/Psychic"},
    {826, "Orbeetle", "Bug/Psychic"},
    {827, "Nickit", "Dark"},
    {828, "Thievul", "Dark"},
    {829, "Gossifleur", "Grass"},
    {830, "Eldegoss", "Grass"},
    {831, "Wooloo", "Normal"},
    {832, "Dubwool", "Normal"},
    {833, "Chewtle", "Water"},
    {834, "Drednaw", "Water/Rock"},
    {835, "Yamper", "Electric"},
    {836, "Boltund", "Electric"},
    {837, "Rolycoly", "Rock"},
    {838, "Carkol", "Rock/Fire"},
    {839, "Coalossal", "Rock/Fire"},
    {840, "Applin", "Grass/Dragon"},
    {841, "Flapple", "Grass/Dragon"},
    {842, "Appletun", "Grass/Dragon"},
    {843, "Silicobra", "Ground"},
    {844, "Sandaconda", "Ground"},
    {845, "Cramorant", "Flying/Water"},
    {846, "Arrokuda", "Water"},
    {847, "Barraskewda", "Water"},
    {848, "Toxel", "Electric/Poison"},
    {849, "Toxtricity", "Electric/Poison"},
    {850, "Sizzlipede", "Fire/Bug"},
    {851, "Centiskorch", "Fire/Bug"},
    {852, "Clobbopus", "Fighting"},
    {853, "Grapploct", "Fighting"},
    {854, "Sinistea", "Ghost"},
    {855, "Polteageist", "Ghost"},
    {856, "Hatenna", "Psychic"},
    {857, "Hattrem", "Psychic"},
    {858, "Hatterene", "Psychic/Fairy"},
    {859, "Impidimp", "Dark/Fairy"},
    {860, "Morgrem", "Dark/Fairy"},
    {861, "Grimmsnarl", "Dark/Fairy"},
    {862, "Obstagoon", "Dark/Normal"},
    {863, "Perrserker", "Steel"},
    {864, "Cursola", "Ghost"},
    {865, "Sirfetch’d", "Fighting"},
    {866, "Mr. Rime", "Ice/Psychic"},
    {867, "Runerigus", "Ground/Ghost"},
    {868, "Milcery", "Fairy"},
    {869, "Alcremie", "Fairy"},
    {870, "Falinks", "Fighting"},
    {871, "Pincurchin", "Electric"},
    {872, "Snom", "Ice/Bug"},
    {873, "Frosmoth", "Ice/Bug"},
    {874, "Stonjourner", "Rock"},
    {875, "Eiscue", "Ice"},
    {876, "Indeedee", "Psychic/Normal"},
    {877, "Morpeko", "Electric/Dark"},
    {878, "Cufant", "Steel"},
    {879, "Copperajah", "Steel"},
    {880, "Dracozolt", "Electric/Dragon"},
    {881, "Arctozolt", "Electric/Ice"},
    {882, "Dracovish", "Water/Dragon"},
    {883, "Arctovish", "Water/Ice"},
    {884, "Duraludon", "Steel/Dragon"},
    {885, "Dreepy", "Dragon/Ghost"},
    {886, "Drakloak", "Dragon/Ghost"},
    {887, "Dragapult", "Dragon/Ghost"},
    {888, "Zacian", "Fairy/Steel"},
    {889, "Zamazenta", "Fighting/Steel"},
    {890, "Eternatus", "Poison/Dragon"},
    {891, "Kubfu", "Fighting"},
    {892, "Urshifu", "Fighting/Dark"},
    {893, "Zarude", "Dark/Grass"},
    {894, "Regieleki", "Electric"},
    {895, "Regidrago", "Dragon"},
    {896, "Glastrier", "Ice"},
    {897, "Spectrier", "Ghost"},
    {898, "Calyrex", "Psychic/Grass"},
    {899, "Wyrdeer", "Normal/Psychic"},
    {900, "Kleavor", "Bug/Rock"},
    {901, "Ursaluna", "Normal/Ground"},
    {902, "Basculegion", "Water/Ghost"},
    {903, "Sneasler", "Fighting/Poison"},
    {904, "Overqwil", "Dark/Poison"},
    {905, "Enamorus", "Fairy/Flying"},
    {906, "Sprigatito", "Grass"},
    {907, "Floragato", "Grass"},
    {908, "Meowscarada", "Grass/Dark"},
    {909, "Fuecoco", "Fire"},
    {910, "Crocalor", "Fire"},
    {911, "Skeledirge", "Fire/Ghost"},
    {912, "Quaxly", "Water"},
    {913, "Quaxwell", "Water"},
    {914, "Quaquaval", "Water/Fighting"},
    {915, "Lechonk", "Normal"},
    {916, "Oinkologne", "Normal"},
    {917, "Tarountula", "Bug"},
    {918, "Spidops", "Bug"},
    {919, "Nymble", "Bug"},
    {920, "Lokix", "Bug/Dark"},
    {921, "Pawmi", "Electric"},
    {922, "Pawmo", "Electric/Fighting"},
    {923, "Pawmot", "Electric/Fighting"},
    {924, "Tandemaus", "Normal"},
    {925, "Maushold", "Normal"},
    {926, "Fidough", "Fairy"},
    {927, "Dachsbun", "Fairy"},
    {928, "Smoliv", "Grass/Normal"},
    {929, "Dolliv", "Grass/Normal"},
    {930, "Arboliva", "Grass/Normal"},
    {931, "Squawkabilly", "Normal/Flying"},
    {932, "Nacli", "Rock"},
    {933, "Naclstack", "Rock"},
    {934, "Garganacl", "Rock"},
    {935, "Charcadet", "Fire"},
    {936, "Armarouge", "Fire/Psychic"},
    {937, "Ceruledge", "Fire/Ghost"},
    {938, "Tadbulb", "Electric"},
    {939, "Bellibolt", "Electric"},
    {940, "Wattrel", "Electric/Flying"},
    {941, "Kilowattrel", "Electric/Flying"},
    {942, "Maschiff", "Dark"},
    {943, "Mabosstiff", "Dark"},
    {944, "Shroodle", "Poison/Normal"},
    {945, "Grafaiai", "Poison/Normal"},
    {946, "Bramblin", "Grass/Ghost"},
    {947, "Brambleghast", "Grass/Ghost"},
    {948, "Toedscool", "Ground/Grass"},
    {949, "Toedscruel", "Ground/Grass"},
    {950, "Klawf", "Rock"},
    {951, "Capsakid", "Grass"},
    {952, "Scovillain", "Grass/Fire"},
    {953, "Rellor", "Bug"},
    {954, "Rabsca", "Bug/Psychic"},
    {955, "Flittle", "Psychic"},
    {956, "Espathra", "Psychic"},
    {957, "Tinkatink", "Fairy/Steel"},
    {958, "Tinkatuff", "Fairy/Steel"},
    {959, "Tinkaton", "Fairy/Steel"},
    {960, "Wiglett", "Water"},
    {961, "Wugtrio", "Water"},
    {962, "Bombirdier", "Flying/Dark"},
    {963, "Finizen", "Water"},
    {964, "Palafin", "Water"},
    {965, "Varoom", "Steel/Poison"},
    {966, "Revavroom", "Steel/Poison"},
    {967, "Cyclizar", "Dragon/Normal"},
    {968, "Orthworm", "Steel"},
    {969, "Glimmet", "Rock/Poison"},
    {970, "Glimmora", "Rock/Poison"},
    {971, "Greavard", "Ghost"},
    {972, "Houndstone", "Ghost"},
    {973, "Flamigo", "Flying/Fighting"},
    {974, "Cetoddle", "Ice"},
    {975, "Cetitan", "Ice"},
    {976, "Veluza", "Water/Psychic"},
    {977, "Dondozo", "Water"},
    {978, "Tatsugiri", "Dragon/Water"},
    {979, "Annihilape", "Fighting/Ghost"},
    {980, "Clodsire", "Poison/Ground"},
    {981, "Farigiraf", "Normal/Psychic"},
    {982, "Dudunsparce", "Normal"},
    {983, "Kingambit", "Dark/Steel"},
    {984, "Great Tusk", "Ground/Fighting"},
    {985, "Scream Tail", "Fairy/Psychic"},
    {986, "Brute Bonnet", "Grass/Dark"},
    {987, "Flutter Mane", "Ghost/Fairy"},
    {988, "Slither Wing", "Bug/Fighting"},
    {989, "Sandy Shocks", "Electric/Ground"},
    {990, "Iron Treads", "Ground/Steel"},
    {991, "Iron Bundle", "Ice/Water"},
    {992, "Iron Hands", "Fighting/Electric"},
    {993, "Iron Jugulis", "Dark/Flying"},
    {994, "Iron Moth", "Fire/Poison"},
    {995, "Iron Thorns", "Rock/Electric"},
    {996, "Frigibax", "Dragon/Ice"},
    {997, "Arctibax", "Dragon/Ice"},
    {998, "Baxcalibur", "Dragon/Ice"},
    {999, "Gimmighoul", "Ghost"},
    {1000, "Gholdengo", "Steel/Ghost"},
    {1001, "Wo-Chien", "Dark/Grass"},
    {1002, "Chien-Pao", "Dark/Ice"},
    {1003, "Ting-Lu", "Dark/Ground"},
    {1004, "Chi-Yu", "Dark/Fire"},
    {1005, "Roaring Moon", "Dragon/Dark"},
    {1006, "Iron Valiant", "Fairy/Fighting"},
    {1007, "Koraidon", "Fighting/Dragon"},
    {1008, "Miraidon", "Electric/Dragon"},
    {1009, "Walking Wake", "Water/Dragon"},
    {1010, "Iron Leaves", "Grass/Psychic"},
    {1011, "Dipplin", "Grass/Dragon"},
    {1012, "Poltchageist", "Grass/Ghost"},
    {1013, "Sinistcha", "Grass/Ghost"},
    {1014, "Okidogi", "Poison/Fighting"},
    {1015, "Munkidori", "Poison/Psychic"},
    {1016, "Fezandipiti", "Poison/Fairy"},
    {1017, "Ogerpon", "Grass"},
    {1018, "Archaludon", "Steel/Dragon"},
    {1019, "Hydrapple", "Grass/Dragon"},
    {1020, "Gouging Fire", "Fire/Dragon"},
    {1021, "Raging Bolt", "Electric/Dragon"},
    {1022, "Iron Boulder", "Rock/Psychic"},
    {1023, "Iron Crown", "Steel/Psychic"},
    {1024, "Terapagos", "Normal"},
    {1025, "Pecharunt", "Poison/Ghost"},
};
char admin[] = "ACER";

// =============================================================
// Function declarations
// =============================================================

void control_center();
void commands(const char *cmd, char *output);
void system_information();
void cpu_usage();
void memory_usage();
void network();
int assistant();
void games();
int numberguessgame();
void update_leaderboard(const char *filename, int score, char currentTrainer[]);
void show_leaderboard(const char *filename);
int tictactoe();
int rock_paper_scissors();
void enableANSI();
void apps();
int age();
void bmi();
void camera();
void takePhoto();
void openPhoto();
void openLatestPhoto();
void listPhotos();
void recordVideo();
void openVideo();
void openLatestVideo();
void listVideos();
void renameMedia();
void deleteMedia();
void calculator();
void calendar();
void Clock();
void conversions();
void number_system();
void Decimal_Binary();
void Decimal_Octal();
void Decimal_Hexadecimal();
void Binary_Decimal();
void Binary_Octal();
void Binary_Hexadecimal();
void Octal_Decimal();
void Octal_Binary();
void Octal_Hexadecimal();
void Hexadecimal_Decimal();
void Hexadecimal_Binary();
void Hexadecimal_Octal();
void unit();
double convert(double value, Unit units[], int from, int to);
void unitCategory(char title[], Unit units[], int size);
void office();
void movie();
void pokedex();
void showPokemonImage(int id);
void songs();

// =============================================================
// Main
// =============================================================

int main()
{
    system("chcp 65001 > nul");
    enableANSI();
    SetConsoleTitle("ROTOM DESK OS");
    int choice, i;
    printf("\x1b[38;2;251;255;8m");
    printf("\nBooting Rotom Desk");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        Sleep(300);
    }
    printf("\x1b[0m");
    printf("\n");
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;251;255;8m");
        printf("╔══════════════════════════════╗\n");
        printf("║         ROTOM DESK OS        ║\n");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;8;255;226m");
        printf("║ 1. Control Center            ║\n");
        printf("║ 2. Rotom Assistant           ║\n");
        printf("║ 3. Games                     ║\n");
        printf("║ 4. Apps                      ║\n");
        printf("║ 5. Exit                      ║\n");
        printf("\x1b[38;2;251;255;8m");
        printf("╚══════════════════════════════╝\n");
        printf("\x1b[0m");

        printf("\nSelect Option: ");
        scanf("%d", &choice);
        printf("==========================\n");

        switch (choice)
        {
        case 1:
            control_center();
            break;
        case 2:
            assistant();
            break;
        case 3:
            games();
            break;
        case 4:
            apps();
            break;
        case 5:
            printf("\x1b[38;2;87;250;193m");
            printf("Rotom: Bzzt! Powering off...\n");
            printf("\x1b[0m");
            exit(0);
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Rotom: Bzzt? Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}

// =============================================================
//  Modules
// =============================================================

void control_center()
{
    int choice, a = 0;
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;0;255;248m");
        printf("╔══════════════════════════════╗\n");
        printf("║        CONTROL CENTER        ║\n");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;132;232;168m");
        printf("║ 1. System Information        ║\n");
        printf("║ 2. CPU Usage                 ║\n");
        printf("║ 3. Memory Usage              ║\n");
        printf("║ 4. Network Status            ║\n");
        printf("║ 5. Exit                      ║\n");
        printf("\x1b[38;2;0;255;248m");
        printf("╚══════════════════════════════╝\n");
        printf("\x1b[0m");
        printf("Select option : ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            system_information();
            break;
        case 2:
            cpu_usage();
            break;
        case 3:
            memory_usage();
            break;
        case 4:
            network();
            break;
        case 5:
            printf("\x1b[38;2;87;250;193m");
            printf("\nExiting Intelligent Control Center...\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void commands(const char *cmd, char *output)
{
    FILE *fp = _popen(cmd, "r");
    if (!fp)
    {
        strcpy(output, "Unavailable");
        return;
    }
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    if (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = 0;
        char *start = buffer;
        while (*start == ' ')
            start++;

        strcpy(output, start);
    }
    else
    {
        strcpy(output, "Unknown");
    }

    _pclose(fp);
}
void system_information()
{
    char desktop[256], processor[256], ram[256];
    char gpu[256], device_id[256], product_id[256], system_type[256];

    commands("wmic computersystem get name", desktop);
    commands("wmic cpu get name", processor);
    commands("wmic computersystem get totalphysicalmemory", ram);
    commands("wmic path win32_VideoController get name", gpu);
    commands("wmic csproduct get uuid", device_id);
    commands("wmic os get serialnumber", product_id);
    commands("wmic os get osarchitecture", system_type);

    system("chcp 65001 > nul");
    system("cls");

    printf("\x1b[38;2;0;245;255m");
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                        System Information                        ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf("\x1b[38;2;127;255;212m");
    printf("║ Desktop Name : %-48.48s  ║\n", desktop);
    printf("║ Processor    : %-48.48s  ║\n", processor);
    printf("║ Installed RAM: %-48.48s  ║\n", ram);
    printf("║ Graphics Card: %-48.48s  ║\n", gpu);
    printf("║ Device ID    : %-48.48s  ║\n", device_id);
    printf("║ Product ID   : %-48.48s  ║\n", product_id);
    printf("║ System Type  : %-48.48s  ║\n", system_type);
    printf("\x1b[38;2;0;245;255m");
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("\nPress Enter to continue...");
    getch();
}
void cpu_usage()
{
    char cpu_usage[256];
    char cpu[4];
    int i;

    while (1)
    {
        commands("wmic cpu get loadpercentage", cpu_usage);

        for (i = 0; i < 3 && cpu_usage[i] != '\0'; i++)
            cpu[i] = cpu_usage[i];

        cpu[i] = '\0';

        system("cls");
        printf("\x1b[38;2;0;224;214m");
        printf("╔══════════════════════╗\n");
        printf("║      CPU MONITOR     ║\n");
        printf("╠══════════════════════╣\n");
        printf("\x1b[38;2;111;231;200m");
        printf("║  Usage : %3s %%       ║\n", cpu);
        printf("╠══════════════════════╣\n");
        printf("\x1b[38;2;0;224;214m");
        printf("║  Press E to Exit     ║\n");
        printf("╚══════════════════════╝\n");
        printf("\x1b[0m");

        Sleep(1000);

        if (_kbhit())
        {
            char ch = getch();
            if (ch == 'e' || ch == 'E')
                break;
        }
    }
}
void memory_usage()
{

    char total_ram[256];
    char free_ram[256];
    long long total = 0, free = 0, p = 1, use;
    float percent;
    int i, t, f;

    commands("wmic OS get TotalVisibleMemorySize ", total_ram);
    commands("wmic OS get FreePhysicalMemory ", free_ram);
    t = strlen(total_ram);
    f = strlen(free_ram);
    for (i = t - 1; i >= 0; i--)
    {
        if (total_ram[i] == ' ')
            continue;
        total += (total_ram[i] - '0') * p;
        p *= 10;
    }
    p = 1;
    for (i = f - 1; i >= 0; i--)
    {
        if (free_ram[i] == ' ')
            continue;
        free += (free_ram[i] - '0') * p;
        p *= 10;
    }
    use = total - free;
    percent = ((float)use / total) * 100;
    system("cls");
    printf("\x1b[38;2;0;217;255m");
    printf("╔══════════════════════════════════╗\n");
    printf("║            Memory Usage          ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("\x1b[38;2;158;255;242m");
    printf("║  Total RAM : %1f GB         ║\n", total / 1024.0 / 1024.0);
    printf("║  Used RAM  : %1f GB         ║\n", use / 1024.0 / 1024.0);
    printf("║  Usage     : %0f %%         ║\n", percent);
    printf("\x1b[38;2;0;217;255m");
    printf("╚══════════════════════════════════╝\n");
    printf("\x1b[0m");

    printf("\nPress Enter to continue...");
    getch();
}
void network()
{
    char ip[256];
    char adapter[256];
    char status[256];

    commands("wmic nic where NetEnabled=true get Name", adapter);
    commands("wmic nic where NetEnabled=true get NetConnectionStatus", status);
    commands("wmic nicconfig where IPEnabled=true get IPAddress", ip);

    system("cls");
    printf("\x1b[38;2;0;242;234m");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                NETWORK STATUS                                                                        ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("\x1b[38;2;155;235;220m");
    printf("║ Adapter Name : %-133s ║\n", adapter);
    printf("║ Status Code  : %-133s ║\n", status);
    printf("║ IP Address   : %-130s  ║\n", ip);
    printf("\x1b[38;2;0;242;234m");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("\nPress Enter to continue...");
    getch();
}
int assistant()
{
    system("cls");

    printf("\x1b[38;2;255;0;136m");
    printf("╔══════════════════════════════════════╗\n");
    printf("\x1b[38;2;212;110;142m");
    printf("║           Rotom Assistant            ║\n");
    printf("\x1b[38;2;255;0;136m");
    printf("╚══════════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Ask your questions(To stop say:/bye)\n");
    system("ollama run llama3.2:latest");
    printf("\nPress Enter to continue...");
    getch();
    return 0;
}
void games()
{
    int choice, a = 0;

    while (1)
    {
        system("cls");
        printf("\x1b[38;2;144;5;255m");
        printf("╔══════════════════════════════════════╗\n");
        printf("║      Welcome to the ROTOM Arcade     ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("\x1b[38;2;143;255;255m");
        printf("║ 1. Guess the Number                  ║\n");
        printf("║ 2. Tic-Tac-Toe with Pikachu          ║\n");
        printf("║ 3. Rock-Paper-Scissors               ║\n");
        printf("║ 4. Snake Game                        ║\n");
        printf("║ 5. Cricket                           ║\n");
        printf("║ 6. Champion Island                   ║\n");
        printf("║ 7. Pony Express                      ║\n");
        printf("║ 8. Exit                              ║\n");
        printf("\x1b[38;2;144;5;255m");
        printf("╚══════════════════════════════════════╝\n");
        printf(" \n");
        printf("\x1b[0m");
        printf("\nSelect Option : ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            numberguessgame();
            break;
        case 2:
            tictactoe();
            break;
        case 3:
            rock_paper_scissors();
            break;
        case 4:
            system("start  https://www.google.com/fbx?fbx=snake_arcade");
            break;
        case 5:
            system("start https://www.google.com/logos/2017/cricket17/cricket17.html?hl=en&origin=www.google.com");
            break;
        case 6:
            system("start https://www.google.com/logos/2020/kitsune/rc7/kitsune20.html?hl=en&origin=www.google.com");
            break;
        case 7:
            system("start https://www.google.com/logos/2015/ponyexpress/ponyexpress15.html?hl=en&origin=www.google.com");
            break;
        case 8:
            printf("\x1b[38;2;87;250;193m");
            printf("\nExiting Rotom Arcade...\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void showPokemonImage(int id)
{
    char command[150];
    sprintf(command, "start images\\%d.png", id);
    system(command);
}
int numberguessgame()
{
    system("cls");
    char filename[20];
    int choice;
    int guess;
    int answer;
    int max = 0, min = 0;
    int attempts = 0;
    char trainer[20];
    srand(time(NULL));

    printf("\x1b[38;2;255;23;130m");
    printf("╔══════════════════════════════════════╗\n");
    printf("║       Number Guessing Game           ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("\x1b[38;2;102;207;255m");
    printf("║ 1. Easy [1-10]                       ║\n");
    printf("║ 2. Normal [1-100]                    ║\n");
    printf("║ 3. Hard [1-1000]                     ║\n");
    printf("║ 4. Find the Pokemon [1-1025]         ║\n");
    printf("\x1b[38;2;255;23;130m");
    printf("╚══════════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Select option : ");
    scanf("%d", &choice);
    printf("Enter trainer name:");
    scanf("%s", trainer);
    if (choice == 1)
    {
        printf("\x1b[38;2;0;255;0m");
        printf("╔════════════════════════════════╗\n");
        printf("║             Easy               ║\n");
        printf("╚════════════════════════════════╝\n");
        printf("\x1b[0m");
        min = 1;
        max = 10;
        strcpy(filename, "easy.dat");
    }
    else if (choice == 2)
    {
        printf("\x1b[38;2;255;255;0m");
        printf("╔════════════════════════════════╗\n");
        printf("║             Normal             ║\n");
        printf("╚════════════════════════════════╝\n");
        printf("\x1b[0m");
        min = 1;
        max = 100;
        strcpy(filename, "normal.dat");
    }
    else if (choice == 3)
    {
        printf("\x1b[38;2;255;0;0m");
        printf("╔════════════════════════════════╗\n");
        printf("║             Hard               ║\n");
        printf("╚════════════════════════════════╝\n");
        printf("\x1b[0m");
        min = 1;
        max = 1000;
        strcpy(filename, "hard.dat");
    }
    else if (choice == 4)
    {
        printf("\x1b[38;2;0;255;208m");
        printf("╔════════════════════════════════╗\n");
        printf("\x1b[38;2;184;255;241m");
        printf("║        Find the Pokemon        ║\n");
        printf("\x1b[38;2;0;255;208m");
        printf("╚════════════════════════════════╝\n");
        printf("\x1b[0m");
        min = 1;
        max = 1025;
        answer = (rand() % (max - min + 1)) + min;
        do
        {

            printf("Enter Pokemon ID:");
            scanf("%d", &guess);
            if (guess < 1 || guess > 1025)
            {
                printf("Invalid ID! Enter between 1 and 1025\n");
                continue;
            }
            if (answer > guess)
            {
                printf("\x1b[38;2;0;255;208m");
                printf("\t( %s )\n", list[guess - 1].name);
                printf("\x1b[38;2;184;255;241m");
                printf("\tToo LOW Pokemon ID!\n");
                printf("\x1b[0m");
            }
            else if (answer < guess)
            {
                printf("\x1b[38;2;0;255;208m");
                printf("\t( %s )\n", list[guess - 1].name);
                printf("\x1b[38;2;184;255;241m");
                printf("\tToo HIGH Pokemon ID!\n");
                printf("\x1b[0m");
            }
            else if (answer == guess)
            {
                printf("\x1b[38;2;0;255;208m");
                printf("You found it!  It's %s \n", list[guess - 1].name);
                printf("\x1b[0m");
            }
            attempts++;
            printf("\x1b[0m");
            printf("-=================================-\n");

        } while (guess != answer);
        showPokemonImage(answer);
        printf("\x1b[38;2;184;255;241m");
        printf("You tried %d times\n", attempts);
        printf("\x1b[0m");
        update_leaderboard("pokemon.dat", attempts, trainer);
        show_leaderboard("pokemon.dat");
        printf("\nPress Enter to continue...");
        getch();
        return 0;
    }
    else
    {
        printf("Invalid option.\n");
        getch();
        return 0;
    }
    answer = (rand() % (max - min + 1)) + min;
    do
    {

        printf("Enter guess:");
        scanf("%d", &guess);
        if (guess < min || guess > max)
        {
            printf("Invalid ID! Enter between %d and %d\n", min, max);
            continue;
        }
        if (answer > guess)
        {
            printf("\x1b[38;2;255;214;10m");
            printf("\tToo LOW !\n");
            printf("\x1b[0m");
        }
        else if (answer < guess)
        {
            printf("\x1b[38;2;255;59;48m");
            printf("\tToo HIGH !\n");
            printf("\x1b[0m");
        }
        else if (answer == guess)
        {
            printf("\x1b[38;2;0;255;136m");
            printf("You found it!  It's %d \n", answer);
            printf("\x1b[0m");
        }
        attempts++;
        printf("\x1b[0m");
        printf("-=================================-\n");

    } while (guess != answer);
    printf("\x1b[38;2;255;215;0m");
    printf("You tried %d times\n", attempts);
    printf("\x1b[0m");
    if (attempts == 1)
    {
        printf("\x1b[38;2;255;215;0m");
        printf("LEGENDARY TRAINER! ONE SHOT!!!\n");
        printf("\x1b[0m");
    }
    update_leaderboard(filename, attempts, trainer);
    show_leaderboard(filename);

    printf("\nPress any key to continue...");
    getch();

    return 0;
}
void update_leaderboard(const char *filename, int score, char currentTrainer[])
{
    HighScore hs[5];
    int count = 0;
    int existingIndex = -1;

    FILE *fp = fopen(filename, "rb");

    if (fp != NULL)
    {
        count = fread(hs, sizeof(HighScore), 5, fp);
        fclose(fp);
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(hs[i].name, currentTrainer) == 0)
        {
            existingIndex = i;
            break;
        }
    }

    if (existingIndex != -1)
    {

        if (score < hs[existingIndex].score)
        {
            hs[existingIndex].score = score;
        }
        else
        {
            return;
        }
    }
    else
    {

        if (count < 5)
        {
            strcpy(hs[count].name, currentTrainer);
            hs[count].score = score;
            count++;
        }
        else
        {
            int worst = 0;

            for (int i = 1; i < 5; i++)
                if (hs[i].score > hs[worst].score)
                    worst = i;

            if (score < hs[worst].score)
            {
                strcpy(hs[worst].name, currentTrainer);
                hs[worst].score = score;
            }
            else
                return;
        }
    }

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (hs[i].score > hs[j].score)
            {
                HighScore temp = hs[i];
                hs[i] = hs[j];
                hs[j] = temp;
            }

    fp = fopen(filename, "wb");
    if (fp != NULL)
    {
        fwrite(hs, sizeof(HighScore), count, fp);
        fclose(fp);
    }
}
void show_leaderboard(const char *filename)
{
    HighScore hs[5];
    int count;

    FILE *fp = fopen(filename, "rb");
    printf("\x1b[38;2;0;255;208m");
    printf("╔════════════════════════════════╗\n");
    printf("\x1b[38;2;184;255;241m");
    printf("║           TOP TRAINERS         ║\n");
    printf("\x1b[38;2;0;255;208m");
    printf("╠════════════════════════════════╣\n");
    printf("\x1b[0m");

    if (fp == NULL)
    {
        printf("No scores yet.\n");
        return;
    }

    count = fread(hs, sizeof(HighScore), 5, fp);
    fclose(fp);
    printf("\x1b[38;2;184;255;241m");
    for (int i = 0; i < count; i++)
        printf("║%-2d %-12s - %-3d attempts  ║\n", i + 1, hs[i].name, hs[i].score);
    printf("\x1b[38;2;0;255;208m");
    printf("╚════════════════════════════════╝\n");
    printf("\x1b[0m");
}
int tictactoe()
{
    int m[3][3] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    char b[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player[5], comp[5];
    int pc = 0, cc = 0;
    int x, r, c, move, i, j, k;

    srand(time(0));

    while (1)
    {
        system("cls");

        printf("\x1b[38;2;0;229;255m");
        printf("╔════════════════════════════════════════════╗\n");

        printf("\x1b[38;2;255;221;0m");
        printf("║          Tic-Tac-Toe with Pikachu          ║\n");

        printf("\x1b[38;2;0;229;255m");
        printf("╚════════════════════════════════════════════╝\n");

        printf("\x1b[0m");

        printf("\n ╔═════════════════╗\n");

        printf(" ║--");
        if (b[0][0] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[0][0] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[0][0]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[0][1] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[0][1] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[0][1]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[0][2] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[0][2] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[0][2]);
        printf("\x1b[0m");
        printf("--║\n");

        printf(" ═══════════════════\n");

        printf(" ║--");
        if (b[1][0] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[1][0] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[1][0]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[1][1] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[1][1] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[1][1]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[1][2] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[1][2] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[1][2]);
        printf("\x1b[0m");
        printf("--║\n");

        printf(" ═══════════════════\n");

        printf(" ║--");
        if (b[2][0] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[2][0] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[2][0]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[2][1] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[2][1] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[2][1]);
        printf("\x1b[0m");
        printf("--║--");

        if (b[2][2] == 'X')
            printf("\x1b[38;2;255;59;48m");
        else if (b[2][2] == 'O')
            printf("\x1b[38;2;0;245;255m");
        else
            printf("\x1b[0m");
        printf("%c", b[2][2]);
        printf("\x1b[0m");
        printf("--║\n");

        printf(" ╚═════════════════╝\n");

        printf("Your move (1-9): ");
        scanf("%d", &x);

        r = (x - 1) / 3;
        c = (x - 1) % 3;

        if (x < 1 || x > 9 || b[r][c] == 'X' || b[r][c] == 'O')
            continue;

        b[r][c] = 'X';
        player[pc++] = m[r][c];

        for (i = 0; i < pc; i++)
            for (j = i + 1; j < pc; j++)
                for (k = j + 1; k < pc; k++)
                    if (player[i] + player[j] + player[k] == 15)
                    {
                        printf("\x1b[38;2;0;255;208m");
                        printf("You Win!\n");
                        printf("\x1b[0m");
                        system("start /wait videos\\sad.mp4");

                        getch();
                        return 0;
                    }

        if (pc + cc == 9)
        {
            printf("\x1b[38;2;0;255;208m");
            printf("Draw!\n");
            printf("\x1b[0m");
            getch();
            return 0;
        }

        move = 0;

        for (i = 0; i < cc; i++)
            for (j = i + 1; j < cc; j++)
            {
                int need = 15 - (comp[i] + comp[j]);
                for (r = 0; r < 3; r++)
                    for (c = 0; c < 3; c++)
                        if (m[r][c] == need && b[r][c] != 'X' && b[r][c] != 'O')
                            move = need;
            }

        if (!move)
            for (i = 0; i < pc; i++)
                for (j = i + 1; j < pc; j++)
                {
                    int need = 15 - (player[i] + player[j]);
                    for (r = 0; r < 3; r++)
                        for (c = 0; c < 3; c++)
                            if (m[r][c] == need && b[r][c] != 'X' && b[r][c] != 'O')
                                move = need;
                }

        if (!move && b[1][1] != 'X' && b[1][1] != 'O')
            move = 5;

        if (!move)
        {
            do
            {
                r = rand() % 3;
                c = rand() % 3;
            } while (b[r][c] == 'X' || b[r][c] == 'O');
            move = m[r][c];
        }

        for (r = 0; r < 3; r++)
            for (c = 0; c < 3; c++)
                if (m[r][c] == move)
                    b[r][c] = 'O';

        comp[cc++] = move;

        for (i = 0; i < cc; i++)
            for (j = i + 1; j < cc; j++)
                for (k = j + 1; k < cc; k++)
                    if (comp[i] + comp[j] + comp[k] == 15)
                    {
                        printf("\x1b[38;2;0;255;208m");
                        printf("Pikachu Wins!\n");
                        printf("\x1b[0m");
                        system("start /wait videos\\happy.mp4");

                        getch();
                        return 0;
                    }

        if (pc + cc == 9)
        {
            printf("\x1b[38;2;0;255;208m");
            printf("Draw!\n");
            printf("\x1b[0m");
            getch();
            return 0;
        }
    }
}
int rock_paper_scissors()
{
    int player, computer;
    char s[3][10] = {"Rock", "Paper", "Scissors"};
    srand(time(NULL));
    computer = rand() % 3 + 1;

    printf("\x1b[38;2;222;24;125m");
    printf("╔════════════════════════════╗\n");
    printf("║     Rock-Paper-Scissors    ║\n");
    printf("╠════════════════════════════╣\n");
    printf("\x1b[38;2;255;199;240m");
    printf("║ 1. Rock                    ║\n");
    printf("║ 2. Paper                   ║\n");
    printf("║ 3. Scissors                ║\n");
    printf("\x1b[38;2;222;24;125m");
    printf("╚════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Choose: ");
    scanf("%d", &player);
    if (player < 1 || player > 3)
    {
        printf("Invalid choice!\n");
        printf("\nPress Enter to continue...");
        getch();
        return 0;
    }
    printf("\x1b[38;2;95;59;110mPlayer : %s\x1b[0m\n", s[player - 1]);
    printf("\x1b[38;2;110;59;100mComputer : %s\x1b[0m\n", s[computer - 1]);
    if (player == computer)
        printf("\x1b[38;2;0;255;255mDraw!\x1b[0m\n");
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2))
        printf("\x1b[38;2;0;255;0mYou Win!\x1b[0m\n");
    else
        printf("\x1b[38;2;255;0;0mComputer Wins!\x1b[0m\n");
    printf("\nPress Enter to continue...");
    getch();
    return 0;
}
void enableANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
void apps()
{
    int choice, a = 0;
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;154;255;87m");
        printf("╔═════════════════════════════════╗\n");
        printf("║               Apps              ║\n");
        printf("╠═════════════════════════════════╣\n");
        printf("\x1b[38;2;0;255;238m");
        printf("║ 1.  Age Calculator              ║\n");
        printf("║ 2.  BMI Calculator              ║\n");
        printf("║ 3.  Camera                      ║\n");
        printf("║ 4.  Calculator                  ║\n");
        printf("║ 5.  Calendar                    ║\n");
        printf("║ 6.  Clock                       ║\n");
        printf("║ 7.  Conversions                 ║\n");
        printf("║ 8.  Drive                       ║\n");
        printf("║ 9.  Email                       ║\n");
        printf("║ 10. Google                      ║\n");
        printf("║ 11. Maps                        ║\n");
        printf("║ 12. Microsoft Office            ║\n");
        printf("║ 13. Pokédex                     ║\n");
        printf("║ 14. Songs                       ║\n");
        printf("║ 15. Translator                  ║\n");
        printf("║ 16. Weather                     ║\n");
        printf("║ 17. Whatsapp                    ║\n");
        printf("║ 18. Youtube                     ║\n");
        printf("║ 19. Exit                        ║\n");
        printf("\x1b[38;2;154;255;87m");
        printf("╚═════════════════════════════════╝\n");
        printf(" \n");
        printf("\x1b[0m");
        printf("\nSelect Option : ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            age();
            break;
        case 2:
            bmi();
            break;
        case 3:
            camera();
            break;
        case 4:
            calculator();
            break;
        case 5:
            calendar();
            break;
        case 6:
            Clock();
            break;
        case 7:
            conversions();
            break;
        case 8:
            system("start https://drive.google.com/");
            break;
        case 9:
            system("start https://mail.google.com");
            break;
        case 10:
            system("start https://google.com");
            break;
        case 11:
            system("start https://www.google.com/maps");
            break;
        case 12:
            office();
            break;
        case 13:
            pokedex();
            break;
        case 14:
            songs();
            break;
        case 15:
            system("start https://translate.google.co.in/?sl=auto&tl=te&op=translate");
            break;
        case 16:
            system("start shell:AppsFolder\\Microsoft.BingWeather_8wekyb3d8bbwe!App");
            break;
        case 17:
            system("start shell:AppsFolder\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App");
            break;
        case 18:
            system("start https://www.youtube.com");
            break;
        case 19:
            printf("\x1b[38;2;87;250;193m");
            printf("Rotom: Bzzt? Exiting Apps!\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
int age()
{
    system("cls");
    int b_day, b_month, b_year;
    int c_day, c_month, c_year;

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    c_day = timeinfo->tm_mday;
    c_month = timeinfo->tm_mon + 1;
    c_year = timeinfo->tm_year + 1900;

    printf("\x1b[38;2;76;201;240m");
    printf("╔═════════════════════════════════════════╗\n");
    printf("\x1b[38;2;255;215;0m");
    printf("║              Age Calculator             ║\n");
    printf("\x1b[38;2;76;201;240m");
    printf("╚═════════════════════════════════════════╝\n");
    printf("\x1b[0m");

    printf("Enter Birth Day: ");
    scanf("%d", &b_day);

    printf("Enter Birth Month: ");
    scanf("%d", &b_month);

    printf("Enter Birth Year: ");
    scanf("%d", &b_year);
    if (b_day <= 0 || b_day > 31)
    {
        printf("Invaild Birth day");
        printf("\nPress Enter to continue...");
        getch();
        return 0;
    }
    if (b_month <= 0 || b_month > 12)
    {
        printf("Invaild Birth month");
        printf("\nPress Enter to continue...");
        getch();
        return 0;
    }
    if (b_year <= 0)
    {
        printf("Invaild Birth year");
        printf("\nPress Enter to continue...");
        getch();
        return 0;
    }

    if (b_day > c_day)
    {
        c_day += 30;
        c_month--;
    }

    if (b_month > c_month)
    {
        c_month += 12;
        c_year--;
    }

    int final_day = c_day - b_day;
    int final_month = c_month - b_month;
    int final_year = c_year - b_year;

    printf("\nYour Age is: %d Years %d Months %d Days\n",
           final_year, final_month, final_day);

    printf("\nPress Enter to continue...");
    getch();
    return 0;
}
void bmi()
{

    system("cls");
    float height, weight, hm, result;
    int choice;
    printf("\x1b[38;2;0;200;120m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;76;201;240m");
    printf("║           BMI Calculator          ║\n");
    printf("\x1b[38;2;0;200;120m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter Weight(in kg): ");
    scanf("%f", &weight);
    printf("\x1b[38;2;76;201;240m");
    printf("╔═══════════════╗\n");
    printf("\x1b[38;2;255;215;0m");
    printf("║     Height    ║\n");
    printf("\x1b[38;2;76;201;240m");
    printf("╠═══════════════╣\n");
    printf("\x1b[38;2;180;255;255m");
    printf("║ 1. Centimetre ║\n");
    printf("║ 2. Feet       ║\n");
    printf("║ 3. Metre      ║\n");
    printf("║ 4. Inch       ║\n");
    printf("\x1b[38;2;76;201;240m");
    printf("╚═══════════════╝\n");
    printf("\x1b[0m");
    printf("Enter choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter Height: ");
        scanf("%f", &height);
        hm = height / 100;
    }
    else if (choice == 2)
    {
        printf("Enter Height: ");
        scanf("%f", &height);
        hm = height / 3.281;
    }
    else if (choice == 3)
    {
        printf("Enter Height: ");
        scanf("%f", &height);
        hm = height;
    }
    else if (choice == 4)
    {
        printf("Enter Height: ");
        scanf("%f", &height);
        hm = height / 39.37;
    }
    else
    {
        printf("Invalid Option.\n");
    }
    result = weight / (hm * hm);

    printf("BMI of the Person : %.2f\n", result);

    if (result < 18.5)
    {
        printf("Underweight\n");
    }
    else if (result < 25)
    {
        printf("\x1b[38;2;0;255;0mHealthy Weight\x1b[0m\n");
    }
    else if (result < 30)
    {
        printf("\x1b[38;2;255;255;0mOverweight\x1b[0m\n");
    }
    else
    {
        printf("\x1b[38;2;255;0;0mObesity\x1b[0m\n");
    }
    printf("\nPress Enter to continue...");
    getch();
}
void camera()
 
{
    int choice, a = 0;
    system("chcp 65001 > nul");
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;80;222;229m");
        printf("╔══════════════════════════════╗\n");
        printf("\x1b[38;2;255;255;255m");
        printf("║           Camera             ║\n");
        printf("\x1b[38;2;80;222;229m");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;255;255;46m");
        printf("║ 1. Take New Photo            ║\n");
        printf("║ 2. Open Photo                ║\n");
        printf("║ 3. Open Latest Photo         ║\n");
        printf("║ 4. List All Photos           ║\n");
        printf("║ 5. Record New Video          ║\n");
        printf("║ 6. Open Video                ║\n");
        printf("║ 7. Open Latest Video         ║\n");
        printf("║ 8. List All Videos           ║\n");
        printf("║ 9. Rename                    ║\n");
        printf("║ 10.Delete                    ║\n");
        printf("║ 11.Exit                      ║\n");
        printf("\x1b[38;2;80;222;229m");
        printf("╚══════════════════════════════╝\n");
        printf("\x1b[0m");
        printf("\nSelect Option: ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            takePhoto();
            break;
        case 2:
            openPhoto();
            break;
        case 3:
            openLatestPhoto();
            break;
        case 4:
            listPhotos();
            break;
        case 5:
            recordVideo();
            break;
        case 6:
            openVideo();
            break;
        case 7:
            openLatestVideo();
            break;
        case 8:
            listVideos();
            break;

        case 9:
            renameMedia();
            break;
        case 10:
            deleteMedia();
            break;
        case 11:
            printf("\x1b[38;2;87;250;193m");
            printf("Rotom: Bzzt? Exiting Camera!\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");

        if (a)
        {
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void takePhoto()
{
    system("start microsoft.windows.camera:");
    printf("Take photo and press ENTER...\n");
    getch();

    system("for /f \"delims=\" %i in ('dir \"%USERPROFILE%\\Pictures\\Camera Roll\\*.jpg\" /b /o-d') do echo %USERPROFILE%\\Pictures\\Camera Roll\\%i > photo.txt & goto :eof");

    printf("Latest photo saved!\n");
    printf("\nPress Enter to continue...");
    getch();
}
void openPhoto()
{
    char command[500];
    char name[100];

    printf("Enter picture name (without extension): ");
    scanf("%s", name);
    sprintf(command,
            "start \"\" \"C:\\Users\\%s\\Pictures\\Camera Roll\\%s.jpg\"",
            admin, name);

    system(command);
    printf("Found it!\n");
    printf("\nPress Enter to continue...");
    getch();
}
void openLatestPhoto()
{
    FILE *fp;
    char filename[300];
    char command[600];

    fp = popen("dir \"%USERPROFILE%\\Pictures\\Camera Roll\\*.jpg\" \"%USERPROFILE%\\Pictures\\Camera Roll\\*.png\" /b /o-d 2>nul", "r");

    if (!fp)
    {
        printf("Error accessing directory.\n");
        getch();
        return;
    }

    if (fgets(filename, sizeof(filename), fp))
    {
        filename[strcspn(filename, "\n")] = 0;

        sprintf(command,
                "cmd /c start \"\" \"%%USERPROFILE%%\\Pictures\\Camera Roll\\%s\"",
                filename);

        system(command);
        printf("Opened latest photo: %s\n", filename);
    }
    else
    {
        printf("No photos found.\n");
    }

    pclose(fp);

    printf("\nPress Enter to continue...");
    getch();
}
void listPhotos()
{
    FILE *fp;
    char filename[300];
    int count = 0;

    system("cls");
    printf("\x1b[38;2;255;80;0m");
    printf("╔══════════════════════╗\n");

    printf("\x1b[38;2;255;255;0m");
    printf("║    Photo Gallery     ║\n");

    printf("\x1b[38;2;255;80;0m");
    printf("╚══════════════════════╝\n\n");

    printf("\x1b[0m");

    fp = popen("dir \"%USERPROFILE%\\Pictures\\Camera Roll\\*.jpg\" \"%USERPROFILE%\\Pictures\\Camera Roll\\*.png\" /b 2>nul", "r");

    if (!fp)
    {
        printf("Error accessing folder.\n");
        getch();
        return;
    }

    while (fgets(filename, sizeof(filename), fp))
    {
        filename[strcspn(filename, "\n")] = 0;
        printf("%d. %s\n", ++count, filename);
    }

    if (count == 0)
    {
        printf("\x1b[38;2;255;0;0m");
        printf("No photos found.\n");
        printf("\x1b[0m");
    }

    pclose(fp);

    printf("\x1b[0m");
    printf("\nTotal Photos: %d\n", count);
    printf("\nPress Enter to continue...");
    getch();
}
void recordVideo()
{

    system("start microsoft.windows.camera:");

    printf("Record video and press ENTER when done...\n");
    getch();
    printf("Latest video saved!\n");

    printf("\nPress Enter to continue...");
    getch();
}
void openVideo()
{
    char command[500];
    char name[100];

    printf("Enter picture name (without extension): ");
    scanf("%s", name);
    sprintf(command,
            "start \"\" \"C:\\Users\\%s\\Pictures\\Camera Roll\\%s.mp4\"",
            admin, name);

    system(command);
    printf("Found it!\n");

    printf("\nPress Enter to continue...");
    getch();
}
void openLatestVideo()
{
    FILE *fp;
    char filename[300];
    char command[600];

    fp = popen("dir \"%USERPROFILE%\\Pictures\\Camera Roll\\*.mp4\" \"%USERPROFILE%\\Pictures\\Camera Roll\\*.mov\" /b /o-d 2>nul", "r");

    if (!fp)
    {
        printf("Error accessing directory.\n");
        getch();
        return;
    }

    if (fgets(filename, sizeof(filename), fp))
    {
        filename[strcspn(filename, "\n")] = 0;

        sprintf(command,
                "cmd /c start \"\" \"%%USERPROFILE%%\\Pictures\\Camera Roll\\%s\"",
                filename);

        system(command);
        printf("Opened latest photo: %s\n", filename);
    }
    else
    {
        printf("No photos found.\n");
    }

    pclose(fp);

    printf("\nPress Enter to continue...");
    getch();
}
void listVideos()
{
    FILE *fp;
    char filename[300];
    int count = 0;

    system("cls");
    printf("\x1b[38;2;255;80;0m");
    printf("╔══════════════════════╗\n");

    printf("\x1b[38;2;255;255;0m");
    printf("║     Video Gallery    ║\n");

    printf("\x1b[38;2;255;80;0m");
    printf("╚══════════════════════╝\n\n");

    printf("\x1b[0m");

    fp = popen("dir \"%USERPROFILE%\\Pictures\\Camera Roll\\*.mp4\" \"%USERPROFILE%\\Pictures\\Camera Roll\\*.mov\" /b 2>nul", "r");

    if (!fp)
    {
        printf("Error accessing folder.\n");
        getch();
        return;
    }

    while (fgets(filename, sizeof(filename), fp))
    {
        filename[strcspn(filename, "\n")] = 0;
        printf("%d. %s\n", ++count, filename);
    }

    if (count == 0)
    {
        printf("\x1b[38;2;255;0;0m");
        printf("No videos found.\n");
        printf("\x1b[0m");
    }

    pclose(fp);

    printf("\x1b[0m");
    printf("\nTotal Videos: %d\n", count);

    printf("\nPress Enter to continue...");
    getch();
}
void renameMedia()
{
    char oldname[100];
    char newname[100];
    char oldPath[400];
    char newPath[400];
    int choice;
    printf("\x1b[38;2;0;255;248m");
    printf("╔══════════════════════════════╗\n");
    printf("║            Rename            ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("\x1b[38;2;132;232;168m");
    printf("║ 1. Picture                   ║\n");
    printf("║ 2. Video                     ║\n");
    printf("\x1b[38;2;0;255;248m");
    printf("╚══════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Select option : ");
    scanf("%d", &choice);
    printf("==========================\n");
    printf("Enter current picture name (without extension): ");
    scanf("%s", oldname);

    printf("Enter new picture name (without extension): ");
    scanf("%s", newname);
    if (choice == 1)
    {
        sprintf(oldPath,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.jpg",
                admin, oldname);

        sprintf(newPath,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.jpg",
                admin, newname);

        if (rename(oldPath, newPath) == 0)
            printf("Photo renamed successfully!\n");
        else
            printf("Rename failed. File not found.\n");
    }
    else if (choice == 2)
    {
        sprintf(oldPath,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.mp4",
                admin, oldname);

        sprintf(newPath,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.mp4",
                admin, newname);

        if (rename(oldPath, newPath) == 0)
            printf("Video renamed successfully!\n");
        else
            printf("Rename failed. File not found.\n");
    }

    printf("\nPress Enter to continue...");
    getch();
}
void deleteMedia()
{
    char name[100];
    char path[400];
    int choice;
    printf("\x1b[38;2;0;255;248m");
    printf("╔══════════════════════════════╗\n");
    printf("║            Delete            ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("\x1b[38;2;132;232;168m");
    printf("║ 1. Picture                   ║\n");
    printf("║ 2. Video                     ║\n");
    printf("\x1b[38;2;0;255;248m");
    printf("╚══════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Select option : ");
    scanf("%d", &choice);
    printf("==========================\n");
    printf("Enter picture name (without extension): ");
    scanf("%s", name);
    if (choice == 1)
    {
        sprintf(path,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.jpg",
                admin, name);

        if (remove(path) == 0)
        {
            printf("Photo deleted successfully!\n");
        }
        else
        {
            printf("Delete failed. File not found.\n");
        }
    }
    else if (choice == 2)
    {
        sprintf(path,
                "C:\\Users\\%s\\Pictures\\Camera Roll\\%s.mp4",
                admin, name);

        if (remove(path) == 0)
            printf("Video deleted successfully!\n");
        else
            printf("Delete failed. File not found.\n");
    }
    else
        printf("Invalid Choice!\n");

    printf("\nPress Enter to continue...");
    getch();
}
void calendar()
{
    int day, month, year;
    int daysInMonth, i;
    int startDay;
    int m, y;
    system("cls");
    printf("\x1b[38;2;147;90;209m");
    printf("╔══════════════════════════════════════╗\n");
    printf("║              Calendar                ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("\x1b[38;2;90;205;209m");
    printf("║  1. January                          ║\n");
    printf("║  2. February                         ║\n");
    printf("║  3. March                            ║\n");
    printf("║  4. April                            ║\n");
    printf("║  5. May                              ║\n");
    printf("║  6. June                             ║\n");
    printf("║  7. July                             ║\n");
    printf("║  8. August                           ║\n");
    printf("║  9. September                        ║\n");
    printf("║ 10. October                          ║\n");
    printf("║ 11. November                         ║\n");
    printf("║ 12. December                         ║\n");
    printf("\x1b[38;2;147;90;209m");
    printf("╚══════════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter month : ");
    scanf("%d", &month);
    if (month <= 0 || month > 12)
    {
        printf("Invalid Month");
    }
    else
    {
        printf("Enter year: ");
        scanf("%d", &year);

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            daysInMonth = 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            daysInMonth = 30;
        else
        {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
        }

        m = month;
        y = year;

        if (m < 3)
        {
            m += 12;
            y--;
        }

        startDay = (1 + (13 * (m + 1)) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        startDay = (startDay + 6) % 7;

        printf("\n\x1b[38;2;90;205;209m  Sun  Mon  Tue  Wed  Thu  Fri  Sat\x1b[0m\n");

        for (i = 0; i < startDay; i++)
            printf("     ");

        for (day = 1; day <= daysInMonth; day++)
        {
            printf("%5d", day);

            if ((day + startDay) % 7 == 0)
                printf("\n");
        }

        printf("\n\n");
    }

    printf("\nPress Enter to continue...");
    getch();
}
void calculator()
{

    char expr[200];
    double nums[100];
    char ops[100];
    int topNum = -1, topOp = -1;

    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++)
    {

        if (isdigit(expr[i]))
        {
            double num = 0;
            while (isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            nums[++topNum] = num;
        }

        else
        {
            while (topOp >= 0 &&
                   ((expr[i] == '+' || expr[i] == '-') &&
                    (ops[topOp] == '*' || ops[topOp] == '/')))
            {

                double b = nums[topNum--];
                double a = nums[topNum--];
                char op = ops[topOp--];

                if (op == '*')
                    nums[++topNum] = a * b;
                if (op == '/')
                    nums[++topNum] = a / b;
            }

            ops[++topOp] = expr[i];
        }
    }

    while (topOp >= 0)
    {
        double b = nums[topNum--];
        double a = nums[topNum--];
        char op = ops[topOp--];

        if (op == '+')
            nums[++topNum] = a + b;
        if (op == '-')
            nums[++topNum] = a - b;
        if (op == '*')
            nums[++topNum] = a * b;
        if (op == '/')
            nums[++topNum] = a / b;
    }

    printf("Result = %.2lf\n", nums[topNum]);

    printf("\nPress Enter to continue...");
    getch();
}
void Clock()
{

    while (1)
    {

        system("cls");
        time_t rawtime;
        struct tm *timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("\x1b[38;2;179;0;78m");
        printf("╔═════════════════════════════════════════╗\n");
        printf("║                  Time                   ║\n");
        printf("╠═════════════════════════════════════════╣\n");
        printf("\x1b[38;2;255;255;0m");
        printf("║               %02d:%02d:%02d                  ║\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        printf("╠═════════════════════════════════════════╣\n");
        printf("\x1b[38;2;179;0;78m");
        printf("║            Press T to Exit              ║\n");
        printf("╚═════════════════════════════════════════╝\n");
        printf("\x1b[0m");

        Sleep(1000);

        if (_kbhit())
        {
            char ch = getch();
            if (ch == 't' || ch == 'T')
                break;
        }
    }

    printf("\nPress Enter to continue...");
    getch();
}
void conversions()
{
    int choice, a = 0;
    system("chcp 65001 > nul");
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;255;20;147m");
        printf("╔══════════════════════════════╗\n");
        printf("\x1b[38;2;255;140;0m");
        printf("║         Conversions          ║\n");
        printf("\x1b[38;2;255;20;147m");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;0;255;0m");
        printf("║ 1. Number System Conversion  ║\n");
        printf("║ 2. Unit Conversion           ║\n");
        printf("║ 3. Exit                      ║\n");
        printf("\x1b[38;2;255;20;147m");
        printf("╚══════════════════════════════╝\n");

        printf("\x1b[0m");
        printf("\nSelect Option: ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            number_system();
            break;
        case 2:
            unit();
            break;
        case 3:
            printf("\x1b[38;2;87;250;193m");
            printf("Rotom: Bzzt? Exiting Conversions!\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");

        if (a)
        {

            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void number_system()
{
    int choice, a = 0;
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;255;20;147m");
        printf("╔══════════════════════════════════════╗\n");
        printf("\x1b[38;2;255;140;0m");
        printf("║     NUMBER SYSTEM CONVERSIONS        ║\n");
        printf("\x1b[38;2;255;20;147m");
        printf("╠══════════════════════════════════════╣\n");
        printf("\x1b[38;2;0;255;0m");
        printf("║ 1 . Decimal      → Binary            ║\n");
        printf("║ 2 . Decimal      → Octal             ║\n");
        printf("║ 3 . Decimal      → Hexadecimal       ║\n");
        printf("║ 4 . Binary       → Decimal           ║\n");
        printf("║ 5 . Binary       → Octal             ║\n");
        printf("║ 6 . Binary       → Hexadecimal       ║\n");
        printf("║ 7 . Octal        → Decimal           ║\n");
        printf("║ 8 . Octal        → Binary            ║\n");
        printf("║ 9 . Octal        → Hexadecimal       ║\n");
        printf("║ 10. Hexadecimal  → Decimal           ║\n");
        printf("║ 11. Hexadecimal  → Binary            ║\n");
        printf("║ 12. Hexadecimal  → Octal             ║\n");
        printf("║ 13. Exit                             ║\n");
        printf("\x1b[38;2;255;20;147m");
        printf("╚══════════════════════════════════════╝\n");

        printf("\x1b[0m");

        printf("\nChoose the option :");
        scanf("%d", &choice);
        printf("---------------------------\n");
        switch (choice)
        {
        case 1:
            Decimal_Binary();
            break;
        case 2:
            Decimal_Octal();
            break;
        case 3:
            Decimal_Hexadecimal();
            break;
        case 4:
            Binary_Decimal();
            break;
        case 5:
            Binary_Octal();
            break;
        case 6:
            Binary_Hexadecimal();
            break;
        case 7:
            Octal_Decimal();
            break;
        case 8:
            Octal_Binary();
            break;
        case 9:
            Octal_Hexadecimal();
            break;
        case 10:
            Hexadecimal_Decimal();
            break;
        case 11:
            Hexadecimal_Binary();
            break;
        case 12:
            Hexadecimal_Octal();
            break;
        case 13:
            printf("\x1b[38;2;87;250;193m");
            printf("\nExiting NUMBER SYSTEM CONVERSIONS...\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {

            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void Decimal_Binary()
{
    double d;
    long long int ind, inp, i;
    int started = 0;
    double frd;
    system("cls");
    printf("\x1b[38;2;0;255;208m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;255;255m");
    printf("║     Decimal → Binary Conversion   ║\n");
    printf("\x1b[38;2;0;255;208m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter Decimal Number : ");
    scanf("%lf", &d);

    if (d == (long long int)d)
    {
        printf("Binary equivalent : ");
        inp = (long long int)d;

        started = 0;
        for (i = 63; i >= 0; i--)
        {
            if ((inp >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%lld", (inp >> i) & 1);
            }
        }

        if (!started)
        {
            printf("Too Large Number.");
        }
    }
    else
    {

        ind = (long long int)d;
        frd = d - ind;

        printf("Binary equivalent : ");

        started = 0;
        for (i = 63; i >= 0; i--)
        {
            if ((ind >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%lld", (ind >> i) & 1);
            }
        }

        if (!started)
            printf("0");

        printf(".");

        for (i = 0; i < 8; i++)
        {
            frd *= 2;
            if ((int)frd == 1)
            {
                printf("1");
                frd -= 1;
            }
            else
            {
                printf("0");
            }
        }
    }

    printf("\nPress Enter to continue...");
    getch();
}
void Decimal_Octal()
{
    int d, k, ind, i, digit;
    float frd, num;
    system("cls");
    printf("\x1b[38;2;0;200;120m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;210;80m");
    printf("║     Decimal → Octal Conversion    ║\n");
    printf("\x1b[38;2;0;200;120m");
    printf("╠═══════════════════════════════════╣\n");
    printf("\x1b[38;2;255;210;80m");
    printf("║ 1.  Integer Decimal               ║\n");
    printf("║ 2.  Float Decimal                 ║\n");
    printf("\x1b[38;2;0;200;120m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Choose option: ");
    scanf("%d", &k);

    if (k == 1)
    {
        printf("Enter Decimal Number: ");
        scanf("%d", &d);
        printf("Octal Equivalent: %o\n", d);
    }
    else if (k == 2)
    {
        printf("Enter Float Decimal Number: ");
        scanf("%f", &num);

        ind = (int)num;
        frd = num - ind;

        printf("Octal Equivalent: %o.", ind);

        for (i = 0; i < 8; i++)
        {
            frd *= 8;
            digit = (int)frd;
            printf("%d", digit);
            frd -= digit;
            if (frd == 0)
                break;
        }
        printf("\n");
    }
    printf("\nPress Enter to continue...");
    getch();
}
void Decimal_Hexadecimal()
{
    int d, k, ind, i, digit;
    float frd, num;
    system("cls");
    printf("\x1b[38;2;170;0;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;240;240;240m");
    printf("║  Decimal → Hexadecimal Conversion ║\n");
    printf("\x1b[38;2;170;0;255m");
    printf("╠═══════════════════════════════════╣\n");
    printf("\x1b[38;2;240;240;240m");
    printf("║ 1.  Integer Decimal               ║\n");
    printf("║ 2.  Float Decimal                 ║\n");
    printf("\x1b[38;2;170;0;255m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Choose option: ");
    scanf("%d", &k);

    if (k == 1)
    {
        printf("Enter Decimal Number: ");
        scanf("%d", &d);
        printf("Hexadecimal Equivalent: %X\n", d);
    }
    else if (k == 2)
    {
        printf("Enter Float Decimal Number: ");
        scanf("%f", &num);

        ind = (int)num;
        frd = num - ind;

        printf("Hexadecimal Equivalent: %X.", ind);

        for (i = 0; i < 8; i++)
        {
            frd *= 16;
            digit = (int)frd;
            if (digit < 10)
                printf("%d", digit);
            else
                printf("%c", 'A' + (digit - 10));

            frd -= digit;
            if (frd == 0)
                break;
        }
        printf("\n");
    }
    printf("\nPress Enter to continue...");
    getch();
}
void Binary_Decimal()
{
    long int b, t, d = 0;
    long int sv, max, half, bit = 0;
    int rem, i, isb;
    system("cls");
    printf("\x1b[38;2;0;120;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║    Binary → Decimal Conversion    ║\n");
    printf("\x1b[38;2;0;120;255m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter  Binary number: ");
    scanf("%ld", &b);
    isb = 1;
    t = b;
    for (i = 0; t > 0; i++)
    {
        rem = t % 10;
        if (rem != 0 && rem != 1)
        {
            isb = 0;
        }
        bit++;
        d += rem * pow(2, i);
        t /= 10;
    }
    if (isb == 1)
    {
        printf("Unsigned Decimal Equivalent: %ld\n", d);
        sv = d;
        max = pow(2, bit);
        half = pow(2, bit - 1);
        if (d >= half)
            sv = d - max;
        printf("Signed Decimal Equivalent(Two\'s Complement): %ld\n", sv);
    }
    else
    {
        printf("Larger binary number or Not a binary number!\n");
    }

    printf("\nPress Enter to continue...");
    getch();
}
void Binary_Octal()
{
    long long int b, t, o = 0;
    long int sv, max, half, bit = 0;
    int rem, i, isb;
    system("cls");

    printf("\x1b[38;2;0;180;180m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;215;0m");
    printf("║      Binary → Octal Conversion    ║\n");
    printf("\x1b[38;2;0;180;180m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Enter Binary number: ");
    scanf("%lld", &b);
    isb = 1;
    t = b;
    for (i = 0; t > 0; i++)
    {
        rem = t % 10;
        if (rem != 0 && rem != 1)
        {
            isb = 0;
        }
        bit++;
        o += rem * pow(2, i);
        t /= 10;
    }
    if (isb == 1)
    {
        printf("Unsigned Octal Equivalent: %o\n", o);
        sv = o;
        max = pow(2, bit);
        half = pow(2, bit - 1);
        if (o >= half)
            sv = o - max;
        printf("Signed Octal Equivalent(Two\'s Complement): %o \n", sv);
    }
    else
        printf("Larger binary number or Not a binary number!\n");

    printf("\nPress Enter to continue...");
    getch();
}
void Binary_Hexadecimal()
{
    long int b, t, h = 0;
    long int sv, max, half, bit = 0;
    int rem, i, isb;
    system("cls");
    printf("\x1b[38;2;170;0;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;240;240;240m");
    printf("║   Binary → Hexadecimal Conversion ║\n");
    printf("\x1b[38;2;170;0;255m");
    printf("╚═══════════════════════════════════╝\n");
    printf("Enter  Binary number: ");
    scanf("%ld", &b);
    isb = 1;
    t = b;
    for (i = 0; t > 0; i++)
    {
        rem = t % 10;
        if (rem != 0 && rem != 1)
        {
            isb = 0;
        }
        bit++;
        h += rem * pow(2, i);
        t /= 10;
    }
    if (isb == 1)
    {
        printf("Unsigned Hexadecimal Equivalent: %X\n", h);
        sv = h;
        max = pow(2, bit);
        half = pow(2, bit - 1);
        if (h >= half)
            sv = h - max;
        printf("Signed Hexadecimal Equivalent(Two\'s Complement): %X \n", sv);
    }
    else
        printf("Larger binary number or Not a binary number!\n");

    printf("\nPress Enter to continue...");
    getch();
}
void Octal_Decimal()
{
    unsigned int o;
    system("cls");
    printf("\x1b[38;2;0;180;0m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;150;255;150m");
    printf("║     Octal → Decimal Conversion    ║\n");
    printf("\x1b[38;2;0;180;0m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Enter Octal Number :");
    scanf("%o", &o);
    printf("Decimal equivalent :%d", o);

    printf("\nPress Enter to continue...");
    getch();
}
void Octal_Binary()
{
    unsigned int o, o1, o2;
    int i, k, started = 0;
    system("cls");
    printf("\x1b[38;2;0;120;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║      Octal → Binary Conversion    ║\n");
    printf("\x1b[38;2;0;120;255m");
    printf("╠═══════════════════════════════════╣\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║ 1.  Integer Octal                 ║\n");
    printf("║ 2.  Float Octal                   ║\n");
    printf("\x1b[38;2;0;120;255m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Choose option:");
    scanf("%d", &k);
    if (k == 1)
    {
        printf("Enter Octal Number:");
        scanf("%o", &o);
        printf("Binary equivalent : ");
        for (i = 31; i >= 0; i--)
        {
            if ((o >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (o >> i) & 1);
            }
        }
        if (!started)
        {
            printf("Not a Octal Number");
        }
    }
    if (k == 2)
    {
        printf("Enter Integer Part:");
        scanf("%o", &o1);
        printf("Enter Fractional Part:");
        scanf("%o", &o2);
        printf("Octal Number :%o.%o\n", o1, o2);
        printf("Binary equivalent : ");
        for (i = 31; i >= 0; i--)
        {
            if ((o1 >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (o1 >> i) & 1);
            }
        }
        printf(".");
        for (i = 15; i >= 0; i--)
        {
            if ((o2 >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (o2 >> i) & 1);
            }
        }
    }

    printf("\nPress Enter to continue...");
    getch();
}
void Octal_Hexadecimal()
{
    unsigned int o;
    system("cls");
    printf("\x1b[38;2;200;0;0m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;240;240;240m");
    printf("║   Octal → Hexadecimal Conversion  ║\n");
    printf("\x1b[38;2;200;0;0m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter Octal Number :");
    scanf("%o", &o);
    printf("Hexadecimal equivalent :%X", o);

    printf("\nPress Enter to continue...");
    getch();
}
void Hexadecimal_Decimal()
{
    int h;
    system("cls");
    printf("\x1b[38;2;0;180;0m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;215;0m");
    printf("║  Hexadecimal → Decimal Conversion ║\n");
    printf("\x1b[38;2;0;180;0m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Enter Hexadecimal Number :");
    scanf("%X", &h);
    printf("Decimal equivalent :%d", h);

    printf("\nPress Enter to continue...");
    getch();
}
void Hexadecimal_Binary()
{
    unsigned int h, h1, h2;
    int i, k, started = 0;
    system("cls");
    printf("\x1b[38;2;170;0;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║  Hexadecimal → Binary Conversion  ║\n");
    printf("\x1b[38;2;170;0;255m");
    printf("╠═══════════════════════════════════╣\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║ 1.  Integer Hexadecimal           ║\n");
    printf("║ 2.  Float Hexadecimal             ║\n");
    printf("\x1b[38;2;170;0;255m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");
    printf("Choose option:");
    scanf("%d", &k);
    if (k == 1)
    {
        printf("Enter Hexadecimal Number :");
        scanf("%X", &h);
        printf("Binary equivalent : ");
        for (i = 31; i >= 0; i--)
        {
            if ((h >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (h >> i) & 1);
            }
        }
        if (!started)
        {
            printf("Not a Hexadecimal Number");
        }
    }
    else if (k == 2)
    {
        printf("Enter Integer Part:");
        scanf("%X", &h1);
        printf("Enter Fractional Part:");
        scanf("%X", &h2);
        printf("Octal Number :%X.%X\n", h1, h2);
        printf("Binary equivalent : ");
        for (i = 31; i >= 0; i--)
        {
            if ((h1 >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (h1 >> i) & 1);
            }
        }
        printf(".");
        for (i = 15; i >= 0; i--)
        {
            if ((h2 >> i) & 1)
            {
                started = 1;
            }
            if (started)
            {
                printf("%d", (h2 >> i) & 1);
            }
        }
    }

    printf("\nPress Enter to continue...");
    getch();
}
void Hexadecimal_Octal()
{
    unsigned int h;
    system("cls");
    printf("\x1b[38;2;0;180;255m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;100;100m");
    printf("║   Hexadecimal → Octal Conversion  ║\n");
    printf("\x1b[38;2;0;180;255m");
    printf("╚═══════════════════════════════════╝\n");
    printf("Enter Hexadecimal Number :");
    scanf("%X", &h);
    printf("Octal equivalent :%o", h);

    printf("\nPress Enter to continue...");
    getch();
}
void unit()
{
    int choice, a = 0;
    system("chcp 65001 > nul");

    Unit length[] = {
        {"mm", 0.001},
        {"cm", 0.01},
        {"m", 1},
        {"km", 1000},
        {"inch", 0.0254},
        {"foot", 0.3048},
        {"yard", 0.9144},
        {"mile", 1609.34}};

    Unit mass[] = {
        {"mg", 0.000001},
        {"g", 0.001},
        {"kg", 1},
        {"tonne", 1000},
        {"pound", 0.453592},
        {"ounce", 0.0283495}};

    Unit time[] = {
        {"second", 1},
        {"minute", 60},
        {"hour", 3600},
        {"day", 86400},
        {"week", 604800},
        {"month", 2628000},
        {"year", 31536000}};

    Unit speed[] = {
        {"m/s", 1},
        {"km/h", 0.277778},
        {"mph", 0.44704},
        {"ft/s", 0.3048},
        {"knot", 0.514444}};

    Unit pressure[] = {
        {"Pascal", 1},
        {"kPa", 1000},
        {"Bar", 100000},
        {"atm", 101325},
        {"mmHg", 133.322},
        {"PSI", 6894.76}};

    Unit storage[] = {
        {"bit", 0.125},
        {"nibble", 0.5},
        {"byte", 1},
        {"KB", 1024},
        {"MB", 1048576},
        {"GB", 1073741824},
        {"TB", 1099511627776.0}};

    while (1)
    {
        system("cls");
        printf("\x1b[38;2;0;255;255m");
        printf("╔══════════════════════════════╗\n");
        printf("\x1b[38;2;255;255;0m");
        printf("║   UNIVERSAL UNIT CONVERTER   ║\n");
        printf("\x1b[38;2;0;255;255m");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;57;255;20m");
        printf("║ 1. Length                    ║\n");
        printf("║ 2. Mass                      ║\n");
        printf("║ 3. Time                      ║\n");
        printf("║ 4. Speed                     ║\n");
        printf("║ 5. Pressure                  ║\n");
        printf("║ 6. Digital Storage           ║\n");
        printf("║ 7. Exit                      ║\n");
        printf("\x1b[38;2;0;255;255m");
        printf("╚══════════════════════════════╝\n");
        printf("\x1b[0m");
        printf("\nSelect Option: ");
        scanf("%d", &choice);
        printf("==========================\n");

        switch (choice)
        {
        case 1:
            unitCategory("Length", length, 8);
            break;
        case 2:
            unitCategory("Mass", mass, 6);
            break;
        case 3:
            unitCategory("Time", time, 7);
            break;
        case 4:
            unitCategory("Speed", speed, 5);
            break;
        case 5:
            unitCategory("Pressure", pressure, 6);
            break;
        case 6:
            unitCategory("Storage", storage, 7);
            break;
        case 7:
            printf("\x1b[38;2;87;250;193m");
            printf("Rotom: Bzzt? Exiting Unit Converter!\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {

            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
double convert(double value, Unit units[], int from, int to)
{
    double baseValue = value * units[from].toBase;
    return baseValue / units[to].toBase;
}
void unitCategory(char title[], Unit units[], int size)
{
    system("cls");
    int i, from, to;
    double value;
    printf("\x1b[38;2;255;0;128m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;255;215;0m");
    printf("║%15s Conversion         ║\n", title);
    printf("\x1b[38;2;255;0;128m");
    printf("╠═══════════════════════════════════╣\n");
    printf("\x1b[38;2;0;255;0m");
    for (i = 0; i < size; i++)
        printf("║%d. %-32s║\n", i + 1, units[i].name);
    printf("\x1b[38;2;255;0;128m");
    printf("╚═══════════════════════════════════╝\n");

    printf("\x1b[0m");

    printf("Select FROM unit: ");
    scanf("%d", &from);

    printf("Select TO unit: ");
    scanf("%d", &to);

    printf("Enter value: ");
    scanf("%lf", &value);

    double result = convert(value, units, from - 1, to - 1);

    printf("Result: %.10lf %s\n", result, units[to - 1].name);

    printf("\nPress Enter to continue...");
    getch();
}
void office()
{
    int choice, a = 0;
    while (1)
    {
        system("cls");
        printf("\x1b[38;2;0;255;248m");
        printf("╔══════════════════════════════╗\n");
        printf("║       Microsoft Office       ║\n");
        printf("╠══════════════════════════════╣\n");
        printf("\x1b[38;2;132;232;168m");
        printf("║ 1. Word                      ║\n");
        printf("║ 2. Excel                     ║\n");
        printf("║ 3. PowerPoint                ║\n");
        printf("║ 4. OneNote                   ║\n");
        printf("║ 5. Access                    ║\n");
        printf("║ 6. Outlook                   ║\n");
        printf("║ 7. Publiser                  ║\n");
        printf("║ 8. Exit                      ║\n");
        printf("\x1b[38;2;0;255;248m");
        printf("╚══════════════════════════════╝\n");
        printf("\x1b[0m");
        printf("Select option : ");
        scanf("%d", &choice);
        printf("==========================\n");
        switch (choice)
        {
        case 1:
            system("start shell:AppsFolder\\Microsoft.Office.WINWORD.EXE.15");
            ;
            break;
        case 2:
            system("start shell:AppsFolder\\Microsoft.Office.EXCEL.EXE.15");
            break;
        case 3:
            system("start shell:AppsFolder\\Microsoft.Office.POWERPNT.EXE.15");
            break;
        case 4:
            system("start shell:AppsFolder\\Microsoft.Office.ONENOTE.EXE.15");
            break;
        case 5:
            system("start shell:AppsFolder\\Microsoft.Office.MSACCESS.EXE.15");
            break;
        case 6:
            system("start shell:AppsFolder\\Microsoft.Office.OUTLOOK.EXE.15");
            break;
        case 7:
            system("start shell:AppsFolder\\Microsoft.Office.MSPUB.EXE.15");
            break;
        case 8:
            printf("\x1b[38;2;87;250;193m");
            printf("\nExiting Microsoft Office...\n");
            printf("\x1b[0m");
            a = 1;
            break;
        default:
            printf("\x1b[38;2;255;0;0m");
            printf("Invalid choice!\n");
            printf("\x1b[0m");
            printf("\nPress Enter to continue...");
            getch();
            break;
        }
        printf("\x1b[0m");
        if (a)
        {

            printf("\nPress Enter to continue...");
            getch();
            break;
        }
    }
}
void pokedex()
{
    system("cls");
    int id;
    int i;

    printf("\x1b[38;2;255;215;0m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;0;255;255m");
    printf("║              Pokédex              ║\n");
    printf("\x1b[38;2;255;215;0m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");
    printf("Enter Pokémon ID: ");
    scanf("%d", &id);
    if (0 < id && id < 1026)
    {
        printf("\x1b[38;2;255;255;0m");
        printf("Rotom :");
        printf("\x1b[0m");
        printf(" Bzzt! Found it -> %s (%s type)\n", list[id - 1].name, list[id - 1].type);
        showPokemonImage(id);
    }
    else
    {
        printf("\x1b[38;2;255;0;0m");
        printf("Rotom: Bzzt? Pokémon not in database!\n");
        printf("\x1b[0m");
    }

    printf("\nPress Enter to continue...");
    getch();
}
void songs()
{
    system("cls");
    char song[200];
    char formatted[400] = "";
    char url[600] = "https://open.spotify.com/search/";

    printf("\x1b[38;2;0;255;208m");
    printf("╔═══════════════════════════════════╗\n");
    printf("\x1b[38;2;184;255;241m");
    printf("║                Song               ║\n");
    printf("\x1b[38;2;0;255;208m");
    printf("╚═══════════════════════════════════╝\n");
    printf("\x1b[0m");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    printf("Enter song name: ");
    fgets(song, sizeof(song), stdin);
    song[strcspn(song, "\n")] = 0;

    if (strlen(song) == 0)
    {
        printf("No song entered!\n");
        printf("\nPress Enter to continue...");
        getch();
        return;
    }

    for (int i = 0; song[i] != '\0'; i++)
    {
        if (song[i] == ' ')
            strcat(formatted, "%20");
        else
        {
            int len = strlen(formatted);
            formatted[len] = song[i];
            formatted[len + 1] = '\0';
        }
    }

    strcat(url, formatted);
    char command[800];
    sprintf(command, "start \"\" \"%s\"", url);
    system(command);

    printf("\nPress Enter to continue...");
    getch();
}