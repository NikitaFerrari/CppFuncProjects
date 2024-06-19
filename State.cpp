#include <iostream>
using namespace std;


class State {
public:
    virtual ~State() = default;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};


class MusicPlayer {
private:
    State* currentState;
    State* stoppedState;
    State* playingState;
    State* pausedState;
public:
    ~MusicPlayer() {
        delete stoppedState;
        delete pausedState;
        delete playingState;
    }

    MusicPlayer();

    void setState(State* state) {
        currentState = state;
    }

    void play() {
        currentState->play();
    }

    void pause() {
        currentState->pause();

    }

    void stop() {
        currentState->stop();
    }


    State* getPlayingState() {
        return playingState;
    }

    State* getStoppedState() {
        return stoppedState;
    }

    State* getPausedState() {
        return pausedState;
    }


};


class StoppedState : public State {
private:
    MusicPlayer* player;
public:
    StoppedState(MusicPlayer* player) : player(player){}
    void play() {
        cout << " Starting playback" << endl;
        player->setState(player->getPlayingState());
    }
    void stop() {
        cout << " Playback is stopped now" << endl;
    }
    void pause() {
        cout << " Playback is paused now" << endl;
    }
};



class PausedState : public State {
private:
    MusicPlayer* player;
public:
    PausedState(MusicPlayer* player) : player(player) {}
    void play() {
        cout << "  Resuming playing" << endl;
        player->setState(player->getPlayingState());
    }
    void stop() {
        player->setState(player->getStoppedState());
        cout << " Playback  stopped " << endl;
    }
    void pause() {
        cout << " Already paused now" << endl;
    }
};


class PlayingState : public State {
private:
    MusicPlayer* player;
public:
    PlayingState(MusicPlayer* player) : player(player) {}
    void play() {
        cout << "  Already playing" << endl;
        
    }
    void stop() {
        player->setState(player->getStoppedState());
        cout << " Playback  stopped " << endl;
    }
    void pause() {
        player->setState(player->getPausedState());
        cout << " Player paused " << endl;
    }
};


MusicPlayer::MusicPlayer() {
    this->stoppedState = new StoppedState(this);
    this->playingState = new PlayingState(this);
    this->pausedState = new PausedState(this);
    currentState = stoppedState;

}


int main()
{
    MusicPlayer player;
    player.play();
    player.stop();
    player.stop();

}
