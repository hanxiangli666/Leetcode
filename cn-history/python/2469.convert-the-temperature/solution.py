class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        kelvin = self._to_kelvin(celsius)
        farenheit = self._to_farenheit(celsius)
        return [kelvin, farenheit]
    def _to_kelvin(self, celsius: float) -> float:
        return celsius + 273.15
    def _to_farenheit(self, celsius: float) -> float:
        return celsius * 1.80 + 32.00
