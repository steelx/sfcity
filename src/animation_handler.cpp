//
// Created by ajink on 25-05-2021.
//

#include "animation_handler.hpp"

void AnimationHandler::Update(const float dt) {
    // if the current animation does not exist, stop
    if (currentAnim >= animations.size() || currentAnim < 0) return;

    float currentAnimDuration = animations[currentAnim].Duration;

    /* Check if the animation has progressed to a new frame and if so
     * change to the next frame
     * */
    if(int((t + dt) / currentAnimDuration) > int(t / currentAnimDuration))
    {
        /* Calculate the frame number */
        int frame = int((t + dt) / currentAnimDuration);

        /* remainder trick to loop in frame */
        frame %= animations[currentAnim].GetLength();

        /* Set the sprite to the new frame */
        sf::IntRect rect = FrameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * currentAnim;
        Bounds = rect;
    }

    /* Increment the time elapsed */
    t += dt;

    /* Adjust for looping */
    if(t > currentAnimDuration * animations[currentAnim].GetLength())
    {
        t = 0.0f;
    }
}

void AnimationHandler::AddAnim(Animation &anim) {
    animations.push_back(anim);
}

void AnimationHandler::ChangeAnim(unsigned int animNum) {
    /* Do not change the animation if the animation is currently active or
     * the new animation does not exist */
    if(currentAnim == animNum || animNum >= animations.size() || animNum < 0) return;

    currentAnim = animNum;

    // update animation Bounds
    sf::IntRect rect = FrameSize;
    rect.top = rect.height * animNum;
    Bounds = rect;
    t = 0.0f;
}
