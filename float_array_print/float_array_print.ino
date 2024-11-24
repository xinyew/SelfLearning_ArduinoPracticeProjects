int indices[5] = {-1, 0, 1, 2, 3};
double data[5] = {
    4.0,
    0.0000555273,
    0.0002756368,
    0.0000666020,
    0.0002730220,};
int length;

uint8_t buffer[4096];

void stuff_buffer() {
    int len = (sizeof(indices)/sizeof(indices[0]));
    length = len * 12;

    uint8_t *tmp_d = (uint8_t*) data;
    uint8_t *tmp_i = (uint8_t*) indices;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 4; j++) {
            buffer[12*i + j] = tmp_i[4*i + j];
        }
        for (int j = 0; j < 8; j++) {
            buffer[12*i + j + 4] = tmp_d[8*i + j];
        }
    }
}


void setup() {
  Serial.begin(9600);
  stuff_buffer();
  delay(100);
  Serial.println("Begin");
  for (int i = 0; i < length/12; i++) {
    int tt = *((int*)(buffer + 12 * i));
    double ttt = *((double*)(buffer + 12 * i + 4));
    Serial.printf("%3d: %.10f\n", tt, ttt);
  }

}

void loop() {
  // Do nothing
}
