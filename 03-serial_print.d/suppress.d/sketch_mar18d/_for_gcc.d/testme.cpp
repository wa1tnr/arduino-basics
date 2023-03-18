#define DEBUGGG false  /* use more resources if true */
#define PPSERIAL                    \
    if (DEBUGGG)                    \
    Serial

const bool Debug = 1; // 0|1 - Should be 0 for productivity builds

void forced() {
    for (volatile int count = 5; count > 0; count--) {
    }
}

// answer 7 from:
// https://arduino.stackexchange.com/questions/9857/can-i-make-the-arduino-ignore-serial-print

static class {
public:
    void begin(...) {}
    void print(...) {}
    void quayle(...) {}
    void println(...) {}
} Serial;

// inserted file is above this line

int fred = 33;

int main() {

    if (Debug == 1)
        // PPSERIAL.begin(9600);
        PPSERIAL.begin(9600);
        PPSERIAL.quayle(fred);
    if (Debug == 1)
        // PPSERIAL.println("-----Reset-----");
        PPSERIAL.println("-----Reset-----");
    forced();
}
// END.
