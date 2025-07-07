package linkedList.ChessLLD;

public class Chess {

    public static void main (String[] args){
        ChessBoard chessBoard = new ChessBoard();
        chessBoard.resetChessBoard();
        chessBoard.printCurrentChessBoard();

    }
    
}

/*
 * 8 x 8 chess game
 * ChessBoard
 * 2 H, 2 G, 2S, 1K, 1Q
 * 8 P
 * (0,0) to (7,7)
 * 
 * 
 * ChessBoardClass
 *  -BoardSquare arr[8][8]
 *BoardSquare
    -String: color
    - boolean : isOccupied
    - ChessPiece: chessPiece
    - int:x
    - int:y
ChessPiece
    -String: color
    -Enum : Type
 * 
 */