#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Pathfinding.h"
#include "PathAgent.h"
#include "Agent.h"
#include "GoToPointBehaviour.h"
#include "WanderBehaviour.h"
#include "FollowBehaviour.h"
#include "DistanceCondition.h"
#include "State.h"
#include "FiniteStateMachine.h"

using namespace AIForGames;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1200;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    std::vector<std::string> asciiMap;
    asciiMap.push_back("0000000000000000000");
    asciiMap.push_back("0101110111011011110");
    asciiMap.push_back("0101011101111110110");
    asciiMap.push_back("0111000001110110010");
    asciiMap.push_back("0101111110110111110");
    asciiMap.push_back("0100000011110110100");
    asciiMap.push_back("0111111100110111110");
    asciiMap.push_back("0100010111011110010");
    asciiMap.push_back("0111010001110111110");
    asciiMap.push_back("0101110000110100110");
    asciiMap.push_back("0100111111110110110");
    asciiMap.push_back("0111100011110111010");
    asciiMap.push_back("0000000000000000000");

    NodeMap nodeMap;
    nodeMap.Intialise(asciiMap, 50);

    std::vector<Agent*> agents;

    Agent* agent1 = new Agent(&nodeMap, new WanderBehaviour());
    agent1->SetNode(nodeMap.GetRandomNode());
    agent1->SetSpeed(256);
    agents.push_back(agent1);

    // set up a FSM, we're going to have two states with their own conditions
    DistanceCondition* closerThan5 = new DistanceCondition(5.0f * nodeMap.GetCellSize(), true);
    DistanceCondition* furtherThan7 = new DistanceCondition(7.0f * nodeMap.GetCellSize(), false);

    // register these states with the FSM, so its responsible for deleting them now
    State* wanderState = new State(new WanderBehaviour());
    State* followState = new State(new FollowBehaviour());
    wanderState->AddTransition(closerThan5, followState);
    followState->AddTransition(furtherThan7, wanderState);

    // make a finite state machine that starts off wandering
    FiniteStateMachine* fsm = new FiniteStateMachine(wanderState);
    fsm->AddState(wanderState);
    fsm->AddState(followState);

    Agent* agent2 = new Agent(&nodeMap, fsm);
    agent2->SetNode(nodeMap.GetRandomNode());
    agent2->SetTargetAgent(agent1);
    agent2->SetSpeed(128);
    agents.push_back(agent2);
    

    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        for (int i = 0; i < agents.size(); i++) {
            agents[i]->Update(deltaTime);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        nodeMap.Draw();
        
        for (int i = 0; i < agents.size(); i++) {
            agents[i]->Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    for (int i = 0; i < agents.size(); i++) {
        delete agents[i];
    }

    return 0;
}