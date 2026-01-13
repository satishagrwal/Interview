#include <iostream>
#include <memory>

using namespace std;

// Forward declarations
class MusicPlayer;
class Idle;
class Playing;
class Paused;
class Stopped;

class State
{
public:
    virtual ~State() = default;

    virtual void start(MusicPlayer&) { invalid(); }
    virtual void pause(MusicPlayer&) { invalid(); }
    virtual void stop(MusicPlayer&)  { invalid(); }

protected:
    void invalid() const
    {
        std::cout << "Invalid operation for current state\n";
    }
};

class MusicPlayer
{
    std::unique_ptr<State> state_;

public:
    MusicPlayer();

    void setState(std::unique_ptr<State> s)
    {
        state_ = std::move(s);
    }

    void start() { state_->start(*this); }
    void pause() { state_->pause(*this); }
    void stop()  { state_->stop(*this); }
};

/* ---- Concrete States ---- */

class Idle : public State
{
public:
    void start(MusicPlayer& m) override;
};

class Playing : public State
{
public:
    void pause(MusicPlayer& m) override;
    void stop(MusicPlayer& m) override;
};

class Paused : public State
{
public:
    void start(MusicPlayer& m) override;
    void stop(MusicPlayer& m) override;
};

class Stopped : public State
{
public:
    void start(MusicPlayer& m) override;
};

/* ---- State Transitions ---- */

MusicPlayer::MusicPlayer()
{
    state_ = std::make_unique<Idle>();
}

void Idle::start(MusicPlayer& m)
{
    std::cout << "Starting playback\n";
    m.setState(std::make_unique<Playing>());
}

void Playing::pause(MusicPlayer& m)
{
    std::cout << "Pausing playback\n";
    m.setState(std::make_unique<Paused>());
}

void Playing::stop(MusicPlayer& m)
{
    std::cout << "Stopping playback\n";
    m.setState(std::make_unique<Stopped>());
}

void Paused::start(MusicPlayer& m)
{
    std::cout << "Resuming playback\n";
    m.setState(std::make_unique<Playing>());
}

void Paused::stop(MusicPlayer& m)
{
    std::cout << "Stopping playback\n";
    m.setState(std::make_unique<Stopped>());
}

void Stopped::start(MusicPlayer& m)
{
    std::cout << "Restarting playback\n";
    m.setState(std::make_unique<Playing>());
}

int main()
{
    MusicPlayer player;

    player.start();
    player.pause();
    player.start();
    player.stop();
}
