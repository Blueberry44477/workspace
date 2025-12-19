import pandas as pd
import kagglehub
import os

movies = pd.read_csv("top10K-TMDB-movies.csv")
music = pd.read_csv("../task1/track_data_final.csv")
games = pd.read_csv("Video_Games.csv")

# Movies
movies_info = movies[["id", "title"]]
movies_genres = movies[["id", "genre"]]

# # music
# music_basic = music[["track_id", "track_name", "artist", "streams"]]
# music_popularity = music[[
#     "track_id",
#     "in_deezer_playlists",
#     "in_apple_playlists"
# ]]

# # Games
# games_info = games[["Name", "Platform", "Year", "Global_Sales"]]
# games_publishers = games[["Name", "Publisher", "NA_Sales", "EU_Sales"]]

print("\nMovies info")
print(movies_info.head())

print("\nMovies genres")
print(movies_genres.head())

# print("\n=== music (head) ===")
# print(music_basic.head())

# print("\n=== Games (head) ===")
# print(games_info.head())


# Movies merge
merged_movies = pd.merge(
    movies_info,
    movies_genres,
    left_on="id",
    right_on="id",
    how="inner",
    indicator=True
)
print("\nMerge Movies (indicator)")
print(merged_movies.head())

# merged_music = pd.merge(
#     music_basic,
#     music_popularity,
#     on="track_id",
#     how="left"
# )
# print("\nMERGE music (left join)")
# print(merged_music.head())

# merged_games = pd.merge(
#     games_info,
#     games_publishers,
#     on="Name",
#     how="outer",
#     indicator=True
# )
# print("\nMERGE Games (outer)")
# print(merged_games.head())

# join
movies_info.set_index("id", inplace=True)
movies_genres.set_index("id", inplace=True)
joined_movies = movies_info.join(movies_genres)
print(f"\nJoin Movies{joined_movies.head()}")

# # music join
# music_basic_idx = music_basic.set_index("track_id")
# music_popularity_idx = music_popularity.set_index("track_id")
# joined_music = music_basic_idx.join(music_popularity_idx, how="inner")
# print("\nJOIN music")
# print(joined_music.head())

# # Games join
# games_info_idx = games_info.set_index("Name")
# games_publishers_idx = games_publishers.set_index("Name")
# joined_games = games_info_idx.join(
#     games_publishers_idx,
#     lsuffix="_info",
#     rsuffix="_pub"
# )
# print("\nJOIN Games")
# print(joined_games.head())
