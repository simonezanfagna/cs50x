SELECT AVG(energy)
FROM songs
JOIN artists on artists.id = songs.artist_id
WHERE artists.name = 'Drake';
