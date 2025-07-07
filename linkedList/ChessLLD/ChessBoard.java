package linkedList.ChessLLD;

public class ChessBoard {
private BoardSquare[][] boardSquares;    

ChessBoard(){
}
public BoardSquare[][] resetChessBoard(){
    BoardSquare[][] boardSquares = new BoardSquare[8][8];
    for(int y = 0;y<8;y++){
        ChessPiece chessPiece = new ChessPiece(ChessPieceType.SOLDIER, "BLACK");
        BoardSquare boardSquare = new BoardSquare( true, chessPiece, 1, y);
        boardSquares[1][y] = boardSquare;
    }
     for(int y = 0;y<8;y++){
        ChessPiece chessPiece = new ChessPiece(ChessPieceType.SOLDIER, "WHITE");
        BoardSquare boardSquare = new BoardSquare( true, chessPiece, 6, y);
        boardSquares[6][y] = boardSquare;
    }
    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            boardSquares[i][j] = new BoardSquare(false, null, i, j);
        }
    }
    initializeMainPiece(boardSquares, "BLACK", 0);
    initializeMainPiece(boardSquares, "WHITE", 7);

    this.boardSquares = boardSquares;
    return boardSquares;
}
private void initializeMainPiece(BoardSquare[][] boardSquares, String color, int x){
boardSquares[x][0] = new BoardSquare(true, new ChessPiece(ChessPieceType.ELEPHANT, color), x, 0);
boardSquares[x][1] = new BoardSquare(true, new ChessPiece(ChessPieceType.HORSE, color), x, 0);
boardSquares[x][2] = new BoardSquare(true, new ChessPiece(ChessPieceType.MANTRI, color), x, 0);
boardSquares[x][3] = new BoardSquare(true, new ChessPiece(ChessPieceType.QUEEN, color), x, 0);
boardSquares[x][4] = new BoardSquare(true, new ChessPiece(ChessPieceType.KING, color), x, 0);
boardSquares[x][5] = new BoardSquare(true, new ChessPiece(ChessPieceType.MANTRI, color), x, 0);
boardSquares[x][6] = new BoardSquare(true, new ChessPiece(ChessPieceType.HORSE, color), x, 0);
boardSquares[x][7] = new BoardSquare(true, new ChessPiece(ChessPieceType.ELEPHANT, color), x, 7);
}

public void printCurrentChessBoard(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            BoardSquare boardSquare = boardSquares[i][j];
            if (!boardSquare.getIsOccupied()){
                System.out.print("| |");
            }else{
                System.out.print("|"+boardSquare.getChessPiece().getChessPieceType()+","+boardSquare.getChessPiece().getColor()+"|");
            }
            
        }
        System.out.println();
    }
}
public BoardSquare[][] getBoardSquares() {
    return this.boardSquares;
}

}
