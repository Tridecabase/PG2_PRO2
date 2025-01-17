#ifndef STAR_GENERATOR_H
#define STAR_GENERATOR_H

#include "Core/xion.h"

void DrawStar(float posX, float posY, float radius, float angleOffset, unsigned int color, unsigned int wirecolor, BlendMode current_mode) {
    float outerPoints[5][2]{};

    for (int i = 0; i < 5; ++i) {
        float outerAngle = angleOffset + i * (2 * static_cast<float>(M_PI) / 5);
        outerPoints[i][0] = posX + static_cast<float>(cos(outerAngle) * radius);
        outerPoints[i][1] = posY + static_cast<float>(sin(outerAngle) * radius);
    }

    Novice::SetBlendMode(BlendMode::kBlendModeNone);

    for (int j = 0; j < 5; ++j) {
        int next = (j + 2) % 5;
        Novice::DrawLine(
            static_cast<int>(outerPoints[j][0]),
            static_cast<int>(outerPoints[j][1]),
            static_cast<int>(outerPoints[next][0]),
            static_cast<int>(outerPoints[next][1]),
            wirecolor
        );
    }

    Novice::SetBlendMode(current_mode);

    for (int j = 0; j < 5; ++j) {
        int next = (j + 2) % 5;
        Novice::DrawTriangle(
            static_cast<int>(outerPoints[j][0]),
            static_cast<int>(outerPoints[j][1]),
            static_cast<int>(outerPoints[next][0]),
            static_cast<int>(outerPoints[next][1]),
            static_cast<int>(posX),
            static_cast<int>(posY),
            color,
            kFillModeSolid
        );
    }

    Novice::SetBlendMode(BlendMode::kBlendModeNone);
}

#endif // !STAR_GENERATOR_H