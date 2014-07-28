/**
 * common.h
 * 
 * Some commonly used defines and configuration options.
 *
 */
#ifndef _COMMON_H_
#define _COMMON_H_

#define MIN_FITNESS (-1000000)
#define MAX_FITNESS (1000000)

/// Players each need to do 40 moves in 2 hours
#define MAX_TIME (20 * 60)	// Not used yet
#define MOVE_COUNT (40)		// Not used yet


/// Minimum ply depth. Except for the standard alpha/beta behaviour,
/// the search depth will not be altered to be less than this, only deeper.
#define __MIN_PLY_DEPTH (5)
/// If 1, only the moves of the current players are regarded (not the countermoves)
/// and are NOT evaluated. Quite useless, so always use > 2.
/// Depth 1 will almost certainly not properly detect when the game has ended, too.
#define MAX_PLY_DEPTH (6)
/// Responses to check do not count as a ply while searching ('check extension'),
/// to prevent eternal loops, there's a maximum of extensions allowed per search path:
#define MAX_EXTRA_PLY_DEPTH (2)
/// When the mininum ply depth is X, this value should be MAX_PLY_DEPTH - X
#define MIN_PLY_DEPTH_REMAINDER (MAX_PLY_DEPTH - __MIN_PLY_DEPTH)
/// Max ply depth used when calculating for the opening book
/// Minimum ply depth will be OPENING_BOOK_MAX_PLY_DEPTH - MIN_PLY_DEPTH_REMAINDER
#define OPENING_BOOK_MAX_PLY_DEPTH (6)
/// If a branch of moves has a quiescence score that it above the threshold,
/// it won't be branched at the minimum ply depth. 
#define QUIESCENCE_THRESHOLD (100)
/// A move adds this many 'points' to its score when it is a capture 
#define QUIESCENCE_PENALTY_CAPTURE (100)
/// A move adds this many 'points' to its score when a piece is pinned
//#define QUIESCENCE_PENALTY_PINNED (60)
/// A move adds this many 'points' to its score when a piece is 'hanging'
// (i.e. attacked and not covered)
//#define QUIESCENCE_PENALTY_HANGING (60)
/// Evaluate moves in random order. Usefull for unpredictability,
/// but cannot be used when alpha/beta in root level
#define MOVE_RANDOMIZE (false)

// Some flags for enabling debug output
#define DRAW_THINKING (false)	/// Prints a few moves, that are being considered
#define DRAW_MOVES (false)		/// Prints all moves at root level
#define DRAW_ALL_MOVES (false)	/// Prints the entire thinking tree
#define DRAW_STATS (false)
#define DEBUG_KEEP_MOVES_SORTED (false)

/// Multithreading. Use 0 to disable, or better yet,
/// disable #define THREADS to disable code completely.
#define MAX_THREADS (4)

// Specifics for Windows and *nix
#if defined(_WIN32) && defined(__GNUC__)
	// Disabled threading on Win32 by not defining THREADS.
	// Disabled utf8-output on win32 by not defining UNICODE_OUTPUT.
	// Enable attempted unicode fix:
	#define UNICODE_FIX	
#else 
 	// Enable multithreading and unicode output
	#define THREADS
	#define UNICODE_OUTPUT
#endif

#endif