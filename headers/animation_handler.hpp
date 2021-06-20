//
// Created by Ajinkya on 25-05-2021.
//

#ifndef SFML_01_ANIMATION_HANDLER_HPP
#define SFML_01_ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    unsigned int StartFrame;
    unsigned int EndFrame;
    float Duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration) {
        this->StartFrame = startFrame;
        this->EndFrame = endFrame;
        this->Duration = duration;
    }

    unsigned int GetLength() {
        return EndFrame - StartFrame + 1;
    }
};

class AnimationHandler {
private:
    std::vector<Animation> animations;

    /// Current time since the animation loop started
    float t;
    /// Current animation frame
    int currentAnim;

public:
    void AddAnim(Animation& anim);

    /// \brief Update the current frame of animation.
    /// \param dt is the time since the update was last called (i.e. the time for one frame to be executed)
    void Update(const float dt);

    /// Change the animation, resetting t in the process
    void ChangeAnim(unsigned int animNum);

    /// Current section of the texture that should be displayed
    sf::IntRect Bounds;

    /// Pixel dimensions of each individual frame
    sf::IntRect FrameSize;

    AnimationHandler() {
        this->t = 0.0f;
        this->currentAnim = -1;
    }

    AnimationHandler(const sf::IntRect& frameSize) {
        this->FrameSize = frameSize;
        this->t = 0.0f;
        this->currentAnim = -1;
    }
};


#endif //SFML_01_ANIMATION_HANDLER_HPP
