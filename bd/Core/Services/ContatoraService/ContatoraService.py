from ..BaseService import BaseService
from bd.Models.Models import ContatoraModel

class ContatoraService(BaseService):
    def __init__(self) -> None:
        super().__init__(ContatoraModel)