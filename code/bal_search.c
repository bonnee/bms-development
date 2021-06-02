uint16_t bal_compute_imbalance(
	voltage_t volts[],
	uint16_t count,
	voltage_t threshold,
	uint16_t imbalance[]) {
	uint16_t indexes = 0;
	uint16_t min_index = _min_index(volts, count);

	for (uint16_t i = 0; i < count; i++) {
		imbalance[i] = max(0, volts[i] - (volts[min_index] + threshold));
		if (imbalance[i] > 0) {
			indexes++;
		}
	}
	return indexes;
}
