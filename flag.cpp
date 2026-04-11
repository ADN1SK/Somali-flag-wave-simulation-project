
// This program simulates a waving Somali flag using OpenGL.
// Compile: g++ flag.cpp -o flag -lGL -lGLEW -lglfw -std=c++17
//run: ./flag
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const int WIDTH = 800;
const int HEIGHT = 600;

// Simple 2D vector used for mesh vertices
struct Vec2 {
    float x;
    float y;
};

// Helper for the pole
void drawPole(float x, float y, float h) {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.02f, y + 0.05f);
    glVertex2f(x, y + 0.05f);
    glVertex2f(x, y - h - 0.5f);
    glVertex2f(x - 0.02f, y - h - 0.5f);
    glEnd();
}

void drawStar(float cx, float cy, float radius) {
    glColor3f(1.0f, 1.0f, 1.0f); // Pure white star
    const int P = 5;
    float innerRadius = radius * 0.381966f;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < P; ++i) {
        float ang = i * 2.0f * M_PI / P - M_PI / 2.0f + M_PI;
        float nextAng = (i + 1) * 2.0f * M_PI / P - M_PI / 2.0f + M_PI;
        float midAng = ang + M_PI / P;

        // Outer triangles
        glVertex2f(cx, cy);
        glVertex2f(cx + radius * cos(ang), cy + radius * sin(ang));
        glVertex2f(cx + innerRadius * cos(midAng), cy + innerRadius * sin(midAng));

        glVertex2f(cx, cy);
        glVertex2f(cx + innerRadius * cos(midAng), cy + innerRadius * sin(midAng));
        glVertex2f(cx + radius * cos(nextAng), cy + radius * sin(nextAng));
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Somali Flag - Wave Simulation", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    float flagW = 1.2f, flagH = 0.8f;
    int rows = 20, cols = 40; // Higher resolution for smoother wave

    while (!glfwWindowShouldClose(window)) {
        float waveTime = (float)glfwGetTime();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Dark background to pop the blue
        glClear(GL_COLOR_BUFFER_BIT);

        float startX = -0.6f, startY = 0.4f;
        drawPole(startX, startY, flagH);

        // Calculate Mesh and Draw Flag
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.447f, 0.808f); // Somali Blue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                auto getWave = [&](int r, int c) {
                    float x = startX + (c * (flagW / cols));
                    float y = startY - (r * (flagH / rows));
                    // Discipline in the math: Frequency + Amplitude
                    float offset = 0.04f * sin(c * 0.3f - waveTime * 2.5f);
                    return Vec2{ x, y + offset };
                };

                auto v1 = getWave(i, j);
                auto v2 = getWave(i, j + 1);
                auto v3 = getWave(i + 1, j + 1);
                auto v4 = getWave(i + 1, j);

                glVertex2f(v1.x, v1.y);
                glVertex2f(v2.x, v2.y);
                glVertex2f(v3.x, v3.y);
                glVertex2f(v4.x, v4.y);
            }
        }
        glEnd();

        // Pin the Star to the center of the wave logic
        float midX = startX + (flagW / 2.0f);
        float midY = startY - (flagH / 2.0f);
        // Use consistent math for the star's vertical displacement
        float starWaveOffset = 0.04f * sin((cols / 2.0f) * 0.3f - waveTime * 2.5f);
        
        drawStar(midX, midY + starWaveOffset, 0.12f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}