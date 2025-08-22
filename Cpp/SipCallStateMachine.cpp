/*📞 SIP Call Lifecycle State Machine in C++
🔹 Typical SIP Call States

Idle – No active call.

InviteSent – Outgoing INVITE sent, waiting for 180/200 OK.

Ringing – 180 Ringing received, waiting for 200 OK.

InCall – 200 OK + ACK exchanged, media established.

Terminated – BYE received/sent, or error.


UML = Idle → InviteSent → Ringing → InCall → Terminated
Events: Events: sendInvite, recv180, recv200, sendACK, sendBYE, recvBYE.*/

#include <iostream>
#include <memory>
#include <string>

class SipCall; // Forward

// Base State
class CallState {
public:
    virtual void sendInvite(SipCall&) { invalid("sendInvite"); }
    virtual void recv180(SipCall&)    { invalid("recv180"); }
    virtual void recv200(SipCall&)    { invalid("recv200"); }
    virtual void sendACK(SipCall&)    { invalid("sendACK"); }
    virtual void sendBYE(SipCall&)    { invalid("sendBYE"); }
    virtual void recvBYE(SipCall&)    { invalid("recvBYE"); }
    virtual ~CallState() = default;
protected:
    void invalid(const std::string& evt) {
        std::cout << "❌ Event '" << evt << "' not allowed in this state.\n";
    }
};

// Forward declare concrete states
class IdleState; class InviteSentState; class RingingState; 
class InCallState; class TerminatedState;

// Context
class SipCall {
    std::shared_ptr<CallState> state;
public:
    SipCall();
    void setState(std::shared_ptr<CallState> s) { state = s; }
    std::shared_ptr<CallState> getState() { return state; }

    // Events
    void sendInvite() { state->sendInvite(*this); }
    void recv180()    { state->recv180(*this); }
    void recv200()    { state->recv200(*this); }
    void sendACK()    { state->sendACK(*this); }
    void sendBYE()    { state->sendBYE(*this); }
    void recvBYE()    { state->recvBYE(*this); }
};

// --- Concrete States ---

class IdleState : public CallState {
public:
    void sendInvite(SipCall& call) override;
};

class InviteSentState : public CallState {
public:
    void recv180(SipCall& call) override;
    void recv200(SipCall& call) override;
};

class RingingState : public CallState {
public:
    void recv200(SipCall& call) override;
};

class InCallState : public CallState {
public:
    void sendBYE(SipCall& call) override;
    void recvBYE(SipCall& call) override;
};

class TerminatedState : public CallState {
public:
    TerminatedState() { std::cout << "📞 Call terminated.\n"; }
};

// --- Implementations ---
void IdleState::sendInvite(SipCall& call) {
    std::cout << "➡️ Sending INVITE...\n";
    call.setState(std::make_shared<InviteSentState>());
}

void InviteSentState::recv180(SipCall& call) {
    std::cout << "📳 180 Ringing received.\n";
    call.setState(std::make_shared<RingingState>());
}
void InviteSentState::recv200(SipCall& call) {
    std::cout << "✅ 200 OK received (direct connect).\n";
    call.setState(std::make_shared<InCallState>());
}

void RingingState::recv200(SipCall& call) {
    std::cout << "✅ 200 OK received after ringing.\n";
    call.setState(std::make_shared<InCallState>());
}

void InCallState::sendBYE(SipCall& call) {
    std::cout << "➡️ Sending BYE...\n";
    call.setState(std::make_shared<TerminatedState>());
}
void InCallState::recvBYE(SipCall& call) {
    std::cout << "📴 BYE received from remote.\n";
    call.setState(std::make_shared<TerminatedState>());
}

// --- SipCall constructor ---
SipCall::SipCall() {
    state = std::make_shared<IdleState>();
}

// --- Demo ---
int main() {
    SipCall call;

    call.sendInvite();   // Idle -> InviteSent
    call.recv180();      // InviteSent -> Ringing
    call.recv200();      // Ringing -> InCall
    call.sendBYE();      // InCall -> Terminated

    return 0;
}
