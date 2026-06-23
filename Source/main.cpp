/*
vcxproj properties setup check list
-----------------------------------
- C/C++ > general > additional include folder > $(SolutionDir)include\raylib; $(SolutionDir)include\
- C/C++ > general > preprocessor > GRAPHICS_API_OPENGL_33; PLATFORM_DESKTOP
- Linker > general > additional Library Directory > $(SolutionDir)Lib\$(Platform)\$(Configuration)\
- Linker > input > additional dependencies > raylib.lib;winmm.lib
*/

#include <raylib.h>
#include <Code_Utilities_Light_v2.h>
#include "Core/GameTest.h"
using namespace BdB;

int main()
{
    //cout << "Hello BdeB!" << std::endl;
   // pressToContinue();

    Core::GameTest{}.run();

    // TodO: breakdown
    // ETQ Développeur, je veux pouvoir créer un arbre de comportement pour mon jeu
    // Task 1: Crée une classe abstraite "Node" qui sera la base de tous les noeuds de l'arbre de comportment --> OK
	// Task 2: Crée une classe "CompositeNode" qui sera la base de tous les noeuds composites (Sequence, Selector, etc.) -- OK
	// Task 3: Crée une classe "LeafNode" qui sera la base de tous les noeuds feuilles (Action, Condition, etc.) --> OK
	// Task 4: Crée une classe "BehaviourTree" qui sera la base de l'arbre de comportement
	// Task 5: Cree une classe "Sequence"
	// Task 6: Cree une class "
	// ETQ Développeur je veux pouvoir rajouter des noeuds à mon arbre de comportement
    // ETQ Développeur je veux pouvoir excécuter mon arbre de comportment
    // ETQ Game Designer, je veux pouvoir utiliser une interface graphique pour crée mon arbre de comportement
	// ETQ Joueur, je veux pouvoir voir les NPC intéragir avec l'environment
}