int LPWM[] = {12, 8, 10}; //  PIN Motor LPWM.
int RPWM[] = {3, 9, 11};  //  PIN Motor RPWM.

// Dieksekusi sekali.
void setup()
{
    Serial.begin(9600);
}

// Dieksekusi berkali-kali setelah void setup.
void loop()
{
    int speed = 187;

    // x:0, y:1 | Robot bergerak maju ke depan.
    kinematis(0, 1, 0, speed);
    delay(1000);

    // x:1, y:1 | Robot bergerak menyerong ke kanan depan.
    kinematis(1, 1, 0, speed);
    delay(1000);

    // x:1, y:0 | Robot bergerak ke kanan.
    kinematis(1, 0, 0, speed);
    delay(1000);

    // x:1, y:-1 | Robot bergerak menyerong ke kanan belakang.
    kinematis(1, -1, 0, speed);
    delay(1000);

    // x:0, y:-1 | Robot bergerak mundur ke belakang.
    kinematis(0, -1, 0, speed);
    delay(1000);

    // x:-1, y:-1 | Robot bergerak menyerong ke kiri belakang.
    kinematis(-1, -1, 0, speed);
    delay(1000);

    // x:-1, y:0 | Robot bergerak ke kiri.
    kinematis(-1, 0, 0, speed);
    delay(1000);

    // x:-1, y:1 | Robot bergerak menyerong ke kiri depan.
    kinematis(-1, 1, 0, speed);
    delay(1000);
}

/* -------------------------------------------------------------------------- */
//
// Fungsi kinematis (4 parameter).
//
// 1st parameter (float x) : Koordinat x (MIN -1, MAx 1).
// 2nd parameter (float y) : Koordinat y (MIN -1, MAx 1).
// 3rd parameter (float theta) : Theta (Normal : 0).
// 4th parameter (int speed) : Kecepatan (MIN 0, MAX 187).
//
/* -------------------------------------------------------------------------- */
void kinematis(float x, float y, float w, int speed)
{
    int m[3];

    m[0] = (x * (-0.5) * speed - y * (sqrt(3) / 2) * speed + w * 0.33);
    m[1] = (x * (-0.5) * speed + y * (sqrt(3) / 2) * speed + w * 0.33);
    m[2] = (x * speed);

    for (int i = 0; i < 3; i++)
    {
        motor(m[i], i);
        Serial.print(m[i]);
        Serial.print("\t");
    }

    Serial.println("");
}

/* -------------------------------------------------------------------------- */
// Fungsi untuk write nilai PWM ke PIN Motor.
/* -------------------------------------------------------------------------- */
void motor(int pwm, int motor)
{
    if (pwm < 0)
    {
        analogWrite(LPWM[motor], abs(pwm));
        analogWrite(RPWM[motor], 0);
    }
    else
    {
        analogWrite(LPWM[motor], 0);
        analogWrite(RPWM[motor], pwm);
    }
}