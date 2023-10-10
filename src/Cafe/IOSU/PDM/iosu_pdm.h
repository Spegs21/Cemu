#pragma once

namespace iosu
{
	namespace pdm
	{
		void save(MemStreamWriter& s);
		void restore(MemStreamReader& s);

		void Initialize();
		void StartTrackingTime(uint64 titleId);
		void Stop();

		inline constexpr size_t NUM_PLAY_STATS_ENTRIES = 256;
		inline constexpr size_t NUM_PLAY_DIARY_ENTRIES_MAX = 18250; // 0x474A

		struct PlayDiaryEntry
		{
			uint64be titleId;
			uint32be ukn08; // probably minutes
			uint16be dayIndex;
			uint16be ukn0E;
		};

		uint32 GetDiaryEntries(uint8 accountSlot, PlayDiaryEntry* diaryEntries, uint32 maxEntries);

		/* Helper for UI game list */
		struct GameListStat
		{
			struct
			{
				uint32 year; // if 0 -> never played
				uint32 month;
				uint32 day;
			}last_played;
			uint32 numMinutesPlayed;
		};

		bool GetStatForGamelist(uint64 titleId, GameListStat& stat);
	};
};