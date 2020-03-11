namespace lib {
class h_bridge {
public:
	h_bridge(int s1, int s2) {
		pinMode(s1, OUTPUT);
		pinMode(s2, OUTPUT);
		m_pin_1 = s1;
		m_pin_2 = s2;
	}
	h_bridge() = default;

	void forward() {
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, HIGH);
	}
	void backward() {
		digitalWrite(m_pin_1, HIGH);
		digitalWrite(m_pin_2, LOW);
	}
	void brake() {
		digitalWrite(m_pin_1, HIGH);
		digitalWrite(m_pin_2, HIGH);
	}
	void coast() {
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, LOW);
	}

private:
	int m_pin_1;
	int m_pin_2;
};
}

lib::h_bridge right_bridge;
lib::h_bridge left_bridge;

void setup() {
	right_bridge = lib::h_bridge(13, 12);
	left_bridge = lib::h_bridge(11, 10);
}

void loop() {
	right_bridge.forward()();
	left_bridge.forward();
	delay(1000);
	right_bridge.backward();
	left_bridge.backward();
	delay(1000);
}
