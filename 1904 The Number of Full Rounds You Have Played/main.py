class Solution:
    def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
        start_hr = int(loginTime[0:2])
        start_min = int(loginTime[3:5])

        end_hr = int(logoutTime[0:2])
        end_min = int(logoutTime[3:5])

        # If logout time is earlier than login time, add 24 hours to the end time
        if start_hr > end_hr or (start_hr == end_hr and start_min > end_min):
            end_hr += 24

        # Convert start and end times to minutes
        ts_min = start_hr * 60 + start_min
        te_min = end_hr * 60 + end_min

        # Round up start time to the nearest 15-minute mark
        if start_min % 15 != 0:
            start_min = (start_min // 15 + 1) * 15
            if start_min == 60:
                start_hr += 1
                start_min = 0

        # Recalculate start time in minutes after rounding
        ts_min = start_hr * 60 + start_min

        # Calculate the number of full 15-minute rounds
        rounds = (te_min - ts_min) // 15

        # Ensure no negative rounds
        return max(0, rounds)