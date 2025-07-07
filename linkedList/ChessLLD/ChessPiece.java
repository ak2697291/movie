package linkedList.ChessLLD;

public class ChessPiece {
    
    private ChessPieceType chessPieceType;
    private String color;

    ChessPiece(ChessPieceType chessPieceType, String color){
        this.chessPieceType = chessPieceType;
        this.color = color;

    }
    public ChessPieceType getChessPieceType() {
        return chessPieceType;
    }
    public void setChessPieceType(ChessPieceType chessPieceType) {
        this.chessPieceType = chessPieceType;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
}
