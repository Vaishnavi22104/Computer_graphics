#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

// Structure to hold a 3D point
typedef struct {
    float x, y, z;
} Point3D;

// Define the 8 vertices of a cube
Point3D cube_vertices[8] = {
    {-50, -50, -50},
    {50, -50, -50},
    {50, 50, -50},
    {-50, 50, -50},
    {-50, -50, 50},
    {50, -50, 50},
    {50, 50, 50},
    {-50, 50, 50}
};

// Define the 12 edges of the cube by connecting vertex indices
int cube_edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Back face
    {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Front face
    {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connecting edges
};


// Function to project a 3D point to 2D screen coordinates
void project_point(Point3D p, int *screen_x, int *screen_y) {
    // A simple perspective projection
    int distance = 200; // Distance of the object from the viewer
    float scale_factor = distance / (distance + p.z);

    *screen_x = (int)(p.x * scale_factor) + getmaxx() / 2;
    *screen_y = (int)(p.y * scale_factor) + getmaxy() / 2;
}


// Function to draw the cube on the screen
void draw_cube(Point3D vertices[]) {
    int i;
    int sx1, sy1, sx2, sy2;

    for (i = 0; i < 12; i++) {
        // Project the two vertices of an edge
        project_point(vertices[cube_edges[i][0]], &sx1, &sy1);
        project_point(vertices[cube_edges[i][1]], &sx2, &sy2);

        // Draw a line between the projected points
        line(sx1, sy1, sx2, sy2);
    }
}

// Function to rotate a point around the X-axis
void rotate_x(Point3D *p, float angle) {
    float rad = angle * M_PI / 180.0;
    float y = p->y;
    p->y = y * cos(rad) - p->z * sin(rad);
    p->z = y * sin(rad) + p->z * cos(rad);
}

// Function to rotate a point around the Y-axis
void rotate_y(Point3D *p, float angle) {
    float rad = angle * M_PI / 180.0;
    float x = p->x;
    p->x = x * cos(rad) + p->z * sin(rad);
    p->z = -x * sin(rad) + p->z * cos(rad);
}

// Function to rotate a point around the Z-axis
void rotate_z(Point3D *p, float angle) {
    float rad = angle * M_PI / 180.0;
    float x = p->x;
    p->x = x * cos(rad) - p->y * sin(rad);
    p->y = x * sin(rad) + p->y * cos(rad);
}

// Function to translate (move) the cube
void translate(Point3D vertices[], float dx, float dy, float dz) {
    int i;
    for (i = 0; i < 8; i++) {
        vertices[i].x += dx;
        vertices[i].y += dy;
        vertices[i].z += dz;
    }
}

// Function to scale (resize) the cube
void scale(Point3D vertices[], float sx, float sy, float sz) {
    int i;
    for (i = 0; i < 8; i++) {
        vertices[i].x *= sx;
        vertices[i].y *= sy;
        vertices[i].z *= sz;
    }
}


int main() {
    int gd = DETECT, gm;
    char ch;
    int i;

    // IMPORTANT: Change this path to where your BGI folder is located
    char bgi_path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, bgi_path);

    // Check for graphics initialization errors
    if (graphresult() != grOk) {
        printf("Graphics error. Check BGI path.\n");
        return 1;
    }

    // Main loop for interaction
    while (1) {
        cleardevice(); // Clear the screen for the new frame

        // Display instructions
        outtextxy(10, 10, "Controls:");
        outtextxy(10, 20, "Arrows: Translate | +/-: Scale | X,Y,Z / A,S,D: Rotate");
        outtextxy(10, 30, "Q: Quit");

        // Draw the current state of the cube
        draw_cube(cube_vertices);
        delay(30); // Control animation speed

        // Check for keyboard input
        if (kbhit()) {
            ch = getch();

            // Quit
            if (ch == 'q' || ch == 'Q') break;

            // --- Transformation Controls ---

            // Scaling
            if (ch == '+') scale(cube_vertices, 1.1, 1.1, 1.1);
            if (ch == '-') scale(cube_vertices, 0.9, 0.9, 0.9);

            // Rotation
            if (ch == 'x') for(i=0; i<8; i++) rotate_x(&cube_vertices[i], 5);
            if (ch == 'a') for(i=0; i<8; i++) rotate_x(&cube_vertices[i], -5);
            if (ch == 'y') for(i=0; i<8; i++) rotate_y(&cube_vertices[i], 5);
            if (ch == 's') for(i=0; i<8; i++) rotate_y(&cube_vertices[i], -5);
            if (ch == 'z') for(i=0; i<8; i++) rotate_z(&cube_vertices[i], 5);
            if (ch == 'd') for(i=0; i<8; i++) rotate_z(&cube_vertices[i], -5);


            // Check for arrow keys (requires two getch() calls)
            if (ch == 0) {
                ch = getch();
                switch (ch) {
                    case 75: translate(cube_vertices, -10, 0, 0); break; // Left
                    case 77: translate(cube_vertices, 10, 0, 0);  break; // Right
                    case 72: translate(cube_vertices, 0, -10, 0); break; // Up
                    case 80: translate(cube_vertices, 0, 10, 0);  break; // Down
                }
            }
        }
    }

    closegraph();
    return 0;
}