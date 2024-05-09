class Node {
    constructor(title, artist, filePath) {
        this.title = title;
        this.artist = artist;
        this.filePath = filePath;
        this.prev = null;
        this.next = null;
        this.audioElement = null;
    }
  }
  
  class CircularDoublyLinkedList {
    constructor() {
        this.currentSong = null;
    }
  
    insertSong(title, artist, filePath) {
        const newSong = new Node(title, artist, filePath);
        const audioElement = document.createElement('audio');
        audioElement.src = filePath;
        newSong.audioElement = audioElement;
  
        if (!this.currentSong) {
            newSong.prev = newSong;
            newSong.next = newSong;
            this.currentSong = newSong;
        } else {
            const lastNode = this.currentSong.prev;
            newSong.prev = lastNode;
            newSong.next = this.currentSong;
            lastNode.next = newSong;
            this.currentSong.prev = newSong;
        }
    }
  
    playCurrentSong() {
        if (this.currentSong) {
            const currentSongElement = document.getElementById("current-song");
            const audioPlayer = document.getElementById("audio-player");
  
            if (currentSongElement && audioPlayer) {
                currentSongElement.innerHTML = `Playing: ${this.currentSong.title} by ${this.currentSong.artist}`;
                audioPlayer.src = this.currentSong.filePath;
                audioPlayer.play();
            } else {
                console.log("Could not find the 'current-song' or 'audio-player' element in the document.");
            }
        } else {
            console.log("No song is currently selected.");
        }
    }
  
    nextSong() {
        if (this.currentSong) {
            this.currentSong = this.currentSong.next;
            this.playCurrentSong();
        } else {
            console.log("No song is currently selected.");
        }
    }
  
    previousSong() {
        if (this.currentSong) {
            this.currentSong = this.currentSong.prev;
            this.playCurrentSong();
        } else {
            console.log("No song is currently selected.");
        }
    }
  }
  
  // Create an instance of CircularDoublyLinkedList
  const playlist = new CircularDoublyLinkedList();
  
  // Example usage:
  playlist.insertSong("Song 1", "Artist 1", "./assets/song1.mp3");
  playlist.insertSong("Song 2", "Artist 2", "./assets/song2.mp3");
  playlist.insertSong("Song 3", "Artist 3", "./assets/song3.mp3");
  
  playlist.playCurrentSong();
  
  // Add event listeners
  const previousSongIcon = document.getElementById("previousSong");
  const playPauseIcon = document.getElementById("playPause");
  const nextSongIcon = document.getElementById("nextSong");
  
  previousSongIcon.addEventListener("click", playlist.previousSong.bind(playlist));
  playPauseIcon.addEventListener("click", playlist.playCurrentSong.bind(playlist));
  nextSongIcon.addEventListener("click", playlist.nextSong.bind(playlist));